class Solution {
public:
    bool isPalindrome(int x) {
        
        // Numeri negativi non possono essere palindromi
        // (es. -121 != 121-)
        if (x < 0) {
            return false;
        }

        // Numeri che finiscono con 0 non sono palindromi
        // tranne il caso 0
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int reversed = 0;

        // Invertiamo solo metà numero
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Caso numeri con numero pari di cifre
        // x == reversed
        //
        // Caso numeri con numero dispari di cifre
        // togliamo la cifra centrale con reversed / 10
        return x == reversed || x == reversed / 10;
    }
};