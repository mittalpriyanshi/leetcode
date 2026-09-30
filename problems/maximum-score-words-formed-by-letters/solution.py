class Solution:
    def maxScoreWords(self, words: list[str], letters: list[str], score: list[int]) -> int:
        freq ={}
        for c in letters:
            freq[c] = freq.get(c,0)+1
        return self.solve(0,freq,words,score)

    def solve(self, i, freq, words,score) -> int:
        if i== len(words):
            return 0
        notTake= self.solve(i+1, freq, words, score)
        newFreq =freq.copy()
        for c in words[i]:
            if newFreq.get(c,0)==0:
                return notTake
            newFreq[c] -=1
        
        scoreTake =0
        for c in words[i]:
            scoreTake += score[ord(c)-ord('a')]
        
        return max(notTake, scoreTake+ self.solve(i+1, newFreq, words, score))


        