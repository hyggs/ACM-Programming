I wrote the code in VS, while submitting on UVa, remember to change scanf_s into scanf otherwise there is a compile error.
# Crypt-Kicker
An ACM problem which took me 3 weeks and finally ... AC!
PC/UVa IDs: 110204/843
A common but insecure method of encrypting text is to permute the letters of the
alphabet. In other words, each letter of the alphabet is consistently replaced in the text
by some other letter. To ensure that the encryption is reversible, no two letters are
replaced by the same letter.
Your task is to decrypt several encoded lines of text, assuming that each line uses
a different set of replacements, and that all words in the decrypted text are from a
dictionary of known words.
Input
The input consists of a line containing an integer n, followed by n lowercase words, one
per line, in alphabetical order. These n words compose the dictionary of words which
may appear in the decrypted text. Following the dictionary are several lines of input.
Each line is encrypted as described above.
There are no more than 1,000 words in the dictionary. No word exceeds 16 letters.
The encrypted lines contain only lower case letters and spaces and do not exceed 80
characters in length.
Output
Decrypt each line and print it to standard output. If there are multiple solutions, any
one will do. If there is no solution, replace every letter of the alphabet by an asterisk.
Sample Input
6
and
dick
jane
puff
spot
yertle
bjvg xsb hxsn xsb qymm xsb rqat xsb pnetfn
xxxx yyy zzzz www yyyy aaa bbbb ccc dddddd
Sample Output
dick and jane and puff and spot and yertle
**** *** **** *** **** *** **** *** ******
