#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class STRING {
        char *s;
        public:

        // default constructor
        STRING() {
                s=new char[100];
        }

        // Parameterized constructor
        STRING(const char *p) {
                s=new char[strlen(p)+1];
                strcpy(s,p);
        }

        // copy constructor
        STRING(const STRING &t) {
                s=new char[strlen(t.s) + 1];
                strcpy(s,t.s);
        }

        //Destructor
        ~STRING() {
                if(s!=nullptr) {
                        delete []s;
                        s=nullptr;
                }
        }

        //Get data
        void getdata() {
                cout<<s <<endl;
        }

        //Assignment operator
        STRING operator = (STRING t) {
                for(int i=0; i<strlen(t.s); i++)
                        s[i]=t.s[i];
                return t;
        }

        // subscript operator
        char& operator [] (int i) {
                //cout<<"operator [] overloaded"<<endl;
                return s[i];
        }

        //Addition operator
        STRING operator + (STRING t2) {
                char *temp=new char[strlen(s)+strlen(t2.s)+1];
                strcpy(temp,s);
                strcat(temp, t2.s);
                STRING result(temp);
                delete []temp;
                return result;
        }

        // Greater than
        bool operator>(const STRING &t) const {
                return strcmp(s,t.s) > 0;
}
        // less than
        bool operator<(const STRING &t) const {
                return strcmp(s,t.s) < 0;
        }

        // greater than or equal to
        bool operator>=(const STRING &t) const {
                return strcmp(s,t.s) >= 0;
        }

        //less than or equal to
        bool operator<= (const STRING &t) const {
                return strcmp(s,t.s)<=0;
        }
        //not equal to
        bool operator!= (const STRING &t) const {
                return strcmp(s,t.s)!=0;
        }

        // equal to
        bool operator== (const STRING &t) const {
                return strcmp(s,t.s)==0;
        }


        friend void strcpy(STRING &,const STRING &);
        friend void strncpy(STRING &,const STRING &, int n);
        friend int strcmp(const STRING &,const STRING &);
        friend int strncmp(const STRING &,const STRING &,int n);
        friend void strcat(STRING &,const STRING &);
        friend void strncat(STRING &,const STRING &,int n);
        friend void strrev(STRING &);
        friend void strupr(STRING &);
        friend void strlwr(STRING &);
        friend const char* strchr(const STRING &,char);
        friend istream& operator >>(istream &, STRING &);
        friend ostream& operator << (ostream &, STRING &);
        friend const char* strrchr(const STRING &,char);
        friend char* strstr(STRING &s1, const STRING &t);
        friend int strlen(STRING l);
};

//stream insertion operator (>>)
istream& operator >> (istream &in,STRING &t) {
        //cout << "operator >> "<<endl;
        in >> t.s;
        return in;
}

// stream extraction operator (<<)
ostream &operator << (ostream &out, STRING &t) {
        //cout <<"operator <<"<<endl;
        out<<t.s;
        return out;
}

// strcpy
void strcpy(STRING &d,const STRING &sr) {
        int i;
        for(i=0;sr.s[i]; i++)
                d.s[i]=sr.s[i];
        d.s[i]='\0';
}

//strncpy
void strncpy(STRING &d,const STRING &sr,int n) {
        int i;
        for(i=0;i<n;i++)
                d.s[i]=sr.s[i];
        d.s[i]='\0';
}

//strcmp
int strcmp(const STRING &s1,const STRING &s2) {
        int i;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]!=s2.s[i])
                        return s1.s[i]-s2.s[i];
        }
        if(s1.s[i]==s2.s[i])
                return 0;
        else
                return -s2.s[i];
}

//strncmp
int strncmp(const STRING &s1,const STRING &s2,int n) {
        int i;
        for(int i=0;i<n;i++)
        {
                if(s1.s[i]!=s2.s[i])
                        return s1.s[i]-s2.s[i];
        }
        if(s1.s[i]==s2.s[i])
                return 0;
        else
                return -s2.s[i];
}

//strcat
void strcat(STRING &s1,const STRING &s2) {
        int i,j;
        for(i=strlen(s1.s),j=0;s2.s[j];i++,j++)
                s1.s[i]=s2.s[j];
        s1.s[i]='\0';
}

//strncat
void strncat(STRING &s1,const STRING &s2,int n) {
        int i,j;
        for(i=strlen(s1.s),j=0;j<n;i++,j++)
                s1.s[i]=s2.s[j];
        s1.s[i]='\0';
}

//strrev
void strrev(STRING &p) {
        int i,len,j;
        char t;
        len=strlen(p.s);
        for(i=0,j=len-1;i<j;i++,j--)
        {
                t=p.s[i];
                p.s[i]=p.s[j];
                p.s[j]=t;
        }
}

//strupr
void strupr(STRING &s1) {
        for(int i=0;s1.s[i];i++)
                                      {
                if(s1.s[i]>='a' && s1.s[i]<='z')
                        s1.s[i]=s1.s[i]-32;
        }
}

//strlwr
void strlwr(STRING &s1) {
        for(int i=0;s1.s[i];i++)
        {
                if(s1.s[i]>='A' && s1.s[i]<='Z')
                        s1.s[i]=s1.s[i]+32;
        }
}

//strchr
const char* strchr(const STRING &s1,char ch) {
        int i;
        for(i=0; s1.s[i]; i++)
                if(s1.s[i]==ch)
                        return &s1.s[i];
        return 0;
}

//strrchr
const char* strrchr(const STRING &s1,char ch) {
        int i;
        i=strlen(s1.s);
        for(i=i-1; i>=0; i--)
                if(s1.s[i]==ch)
                return &s1.s[i];
        return 0;
}

//strstr
char* strstr(STRING &m, const STRING &s) {
        int i,j=0;
        for(i=0; m.s[i]; i++)
        {
                if(m.s[i] == s.s[j])
                {
                        for(j=1; s.s[j] ;j++)
                        {
                                if(s.s[j] != m.s[++i])
                                        break;
                        }
                        if(s.s[j]==0)
                                return (m.s)+i-1;
                        j=0;
                }
        }
        return 0;
}

//strlen
int strlen(STRING l) {
        int i;
  for(i=0;l.s[i]; i++);
        return i;
}


int main() {
        STRING s1,s2("Vector"),s3(s2),s4,s5;
        cout<< "enter a string : ";
        cin>>s1;
        cout <<endl;

        cout <<"default constructor s1------------> = "<<s1<<endl;
        cout <<"parameterized constructors2-------> = " <<s2 <<endl;
        cout <<"copy contructor s3 ---------------> = "<< s3 <<endl;
        s4=s1;
        cout << "assignment operator s4=s1--------> = "<<s4 <<endl;
        s4=s1+s2;
        cout << "concatentation of two strings s4=s1+s2 -> = "<<s4<<endl;
        cout << "s1>s2  ----> = " << (s1>s2) <<endl;
        cout << "s1<s2  ----> = " << (s1<s2) <<endl;
        cout << "s1>=s2 ----> = " << (s1>=s2) <<endl;
        cout << "s1<=s2 ----> = " << (s1<=s2) <<endl;
        cout << "s1==s2 ----> = " << (s1==s2) <<endl;
        cout << "s1!=s2 ----> = " << (s1!=s2) <<endl;
        cout << "strelen(s1) ------> = " << strlen(s1) <<endl;
        strcpy(s2,s1);
        cout << "strcpy(s2,s1) ----> s2= " << s2 <<endl;
        strcat(s3,s1);
        cout<< "strcat(s3,s1)  ---->s3= " << s3 <<endl;

        const char *p2=strchr(s3,'t');
        if(p2==nullptr)
                cout<< "strchr(s3,'t') ----> character not found" <<endl;
        else
                cout<< "strchr(s3,'t') ----> " <<p2<<endl;

        strupr(s4);
        strlwr(s1);
        cout <<" strupr(s4)---->s4 = "<<s4 <<endl;
        cout <<" strlwr(s1)---->s1 = "<<s1 <<endl;
        cout <<" strcmp(s1,s3)->"<<strcmp(s1,s3)<<endl;
        cout <<" enter a string: ";
        cin>>s5;
        cout<< " s5 ---> = "<<s5 <<endl;
        const char *j=strstr(s3,s5);
        if(j==nullptr)
                cout<<"substring not found"<<endl;
        else
        cout<<" strstr(s3,s5)----->"<<strstr(s3,s5)<<endl;

        strrev(s2);
        cout<<" strrev(s2)----->s2= "<<s2<<endl;

        strncat(s5,s1,2);
        cout<<" strncat(s5,s1,2)-->s5= "<<s5<<endl;

        STRING s6;
        strncpy(s6,s5,3);
        cout<<" strncpy(s6,s5,3)-->s6= "<<s6<<endl;
        cout<<" strncmp(s5,s6,3)-->"<<strncmp(s5,s6,3)<<endl;

        const char *p=strchr(s5,'t');
        if(p==nullptr)
	  cout<<" strchr(s5,'t')---->charchter not found"<<endl;
        else
                cout<<" strrchr(s5,'t')--->"<<p<<endl;
}

