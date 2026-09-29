class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        mp={}
        for i in range (n):
            mp[nums[i]] = i
        #complement finding now
        for i in range (n):
            complement = target - nums[i]
            if complement in mp and mp[complement]!=i:
                return [i, mp[complement]]
        return []