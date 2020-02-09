/*
Note: This is a companion problem to the System Design problem: Design TinyURL.

TinyURL is a URL shortening service where you enter a URL such 
as https://leetcode.com/problems/design-tinyurl and it returns a 
short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. 
There is no restriction on how your encode/decode algorithm should work.
 You just need to ensure that a URL can be encoded to a tiny URL and 
 the tiny URL can be decoded to the original URL.
*/

//solution
class Solution {
public:
    int count = 1;
    unordered_set<string> encodedUrls;
    unordered_map<string, string> tinyToBig;
    char buffer[62]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
                  
    string getTiny(int value){
        string str;
        while(value){
            str.append(1, buffer[value%62]);
            value = value/62;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    
    int getSlot(string str){
        int numb = 0;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i]>='a'&&str[i]<='z')
                numb = numb * 62 + (str[i]-'a'+1);
            else if(str[i]>='A'&&str[i]<='Z')
                numb = numb * 62 + (str[i]-'A'+26);
            else if(str[i]>='0'&&str[i]<='9')
                numb = numb * 62 + (str[i]-'0'+52);
        }
        return numb;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str;
        if(encodedUrls.find(longUrl) == encodedUrls.end()){
            encodedUrls.insert(longUrl);
            str = move(getTiny(count));
            tinyToBig[str] = longUrl;
            count++;
        }
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tinyToBig[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));