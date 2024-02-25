#include <bits/stdc++.h>
using namespace std;

class chaine{
    private:
        const char* str;
        int len;
    public:
        chaine(const char* s = nullptr, int l = 0){
            if(s == nullptr) return;
            if(l == 0) this->len = strlen(s);
            char *str_cpy = new char[strlen(s)+1];
            str_cpy[strlen(s)] = '\0';
            for(int i = 0; i < this->len; i++){
                str_cpy[i] = s[i];
            }
            this->str = str_cpy;
        }

        chaine(int s, int l = 0){ 
            if(s == 0) return;

            int tmp = s;  
            int count = 0; 

            while(tmp > 0){
                tmp/=10;
                count++;
            }

            this->len = max(count, l);

            char* str_cpy = new char[this->len + 1];
            str_cpy[this->len] = '\0';

            for(int i = this->len-1; i >= 0; --i){
                str_cpy[i] = static_cast<char>(s % 10 + '0');
                s /= 10;
            }

            this->str = str_cpy;
        }

        chaine(const chaine &chaine_obj){
            char* str_cpy = new char[chaine_obj.len +1];
            str_cpy[chaine_obj.len] =  '\0';
            this->len = chaine_obj.len;
            for(int i = 0; i < chaine_obj.len; i++){
                str_cpy[i] = chaine_obj.str[i];
            }
            this->str = str_cpy;
        }

        chaine operator+(chaine &chaine_obj){
            chaine res;
            res.len = this->len + chaine_obj.len;
            char *str_cpy = new char[this->len + chaine_obj.len + 1];
            str_cpy[this->len + chaine_obj.len] = '\0';
            for(int i = 0; i < this->len + chaine_obj.len; ++i){
                if(i < this->len) str_cpy[i] = this->str[i];
                else str_cpy[i] = chaine_obj.str[i-this->len];
            }
            res.str = str_cpy;
            return res;
        }

        friend std::ostream& operator<<(std::ostream& os, const chaine &obj) {
            os<<obj.str;
            return os;
        }   
};


int main(){
    chaine s1("SALUT");
    chaine s2(" BB");
    chaine s3 = s1 + s2; 
    cout<<s3<<endl;
    return 0;
}
