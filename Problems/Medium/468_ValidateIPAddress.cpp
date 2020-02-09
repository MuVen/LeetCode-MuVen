/*
Write a function to check whether an input string is a valid IPv4 address or
 IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which 
consists of four decimal numbers, each ranging from 0 to 255, separated by 
dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address
 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, 
each group representing 16 bits. The groups are separated by colons (":"). 
For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. 
Also, we could omit some leading zeros among four hexadecimal digits and some 
low-case characters in the address to upper-case ones, 
so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address
(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a 
single empty group using two consecutive colons (::) to pursue simplicity.
 For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. 
For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters 
in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

//solution
class Solution {
    vector<string> ips;
public:
    bool isIP4v(){
        for(int i = 0; i < 4; i++){
            string str = ips[i];
            if(str.length() > 1 && str[0] == '0')
                return false;
            int number = 0;
            for(int i = 0; str[i] != '\0'; i++){
                number = number * 10 + (str[i]-'0');
            }
            if(number > 255)
                return false;
        }
        return true;
    }
    
    bool isIP6v(){
        for(int i = 0; i < 8; i++){
            string str = ips[i];
            cout<<str<<" ";
            if(str.length() > 4)
                return false;
            for(int i = 0; str[i] != '\0'; i++){
                if((str[i]>='0' && str[i]<='9') ||
                   (str[i]>='a' && str[i]<='f') ||
                   (str[i]>='A' && str[i]<='F'))
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        string temp;
        int dcount=0, ccount=0;
        for(int i = 0; IP[i] != '\0'; i++){
            if(IP[i] == '.'){
                if(temp.length() > 0 && temp.length() <= 4){
                    ips.push_back(temp);
                    dcount++;
                    temp.clear();    
                }else
                    return "Neither";
            }else if(IP[i] == ':'){
                if(temp.length() > 0 && temp.length() <= 4){
                    ips.push_back(temp);
                    ccount++;
                    temp.clear();    
                }else
                    return "Neither";        
            }
            else{
                if(IP[i] >= '0' && IP[i] <= '9' ||
                   IP[i] >= 'a' && IP[i] <= 'f' ||
                   IP[i] >= 'A' && IP[i] <= 'F')
                temp += IP[i];
                else
                    return "Neither";
            }
        }
        if(temp.length() > 0 && temp.length() <= 4)
            ips.push_back(temp);
        
        for(auto s : ips)
            cout<<s<<" ";
        cout<<endl;
        
        if(dcount == 3 && ccount == 0 && ips.size() == 4){
            if(isIP4v())
                return "IPv4";
            return "Neither";
        }
        
        if(dcount == 0 && ccount == 7 && ips.size() == 8){
            if(isIP6v())
                return "IPv6";
            return "Neither";    
        }
        
        return "Neither";    
    }
};