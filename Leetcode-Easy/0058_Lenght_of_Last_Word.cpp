class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        // Salta gli spazi finali
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int length = 0;
        // Conta i caratteri dell'ultima parola
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};