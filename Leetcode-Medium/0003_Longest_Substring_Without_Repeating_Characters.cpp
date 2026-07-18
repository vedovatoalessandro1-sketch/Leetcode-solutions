class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            
            // Se troviamo un duplicato, togliamo caratteri da sinistra
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }

            // Aggiungiamo il nuovo carattere
            window.insert(s[right]);

            // Aggiorniamo la risposta
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};