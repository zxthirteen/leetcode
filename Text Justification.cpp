/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        auto i = words.begin();
        while (i != words.end()) {
            auto start = i;
            int wordcount = 0;
            int charcount = 0;
            while (i != words.end() && charcount + wordcount + (*i).size() <= L) {
                wordcount++;
                charcount += (*i).size();
                i++;
            }
            string line = "";
            if (i != words.end()) {
                if (wordcount == 1) {
                    line = *start + string(L - charcount, ' ');
                } else {
                    int allspace = L - charcount;
                    int everyspace = allspace/(wordcount -1);
                    int extraspace = allspace%(wordcount -1);
                    for (auto j = start; j != start + wordcount; j++) {
                        line += *j;
                        if (j != start + wordcount -1) {
                            line += string(everyspace, ' ');
                            if (j - start + 1 <= extraspace) {
                                line += ' ';
                            }
                        }
                    }
                }
            } else {
                for (auto j = start; j != start + wordcount; j++) {
                    line += *j;
                    if (j != start+wordcount -1) {
                        line += ' ';
                    }
                }
                for (int t = 0; t < L - wordcount - charcount +1; t++) {
                    line += ' ';
                }
            }
            result.push_back(line);
        }
        return result;
    }
};