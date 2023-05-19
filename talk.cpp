#include <windows.h>
#include <string.h>
#include <sapi.h>
#include <stdio.h>

 //_____________________________________________________________________________________________________________________________________ 
   unsigned char LettersNumbers[]
 //_____________________________________________________________________________________________________________________________________ 
 //  0   1   2   3   4   5   6   7     8   9  10  11  12  13  14  15    16  17  18  19  20  21  22  23    24  25  26  27  28  29  30  31 
 // 00  01  02  03  04  05  06  07    08  09  0A  0B  0C  0D  0E  0F    10  11  12  13  14  15  16  17    18  19  1A  1B  1C  1D  1E  1F 
 ={  0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________ 
 // 32  33  34  35  36  37  38  39    40  41  42  43  44  45  46  47    48  49  50  51  52  53  54  55    56  57  58  59  60  61  62  63 
 // 20  21  22  23  24  25  26  27    28  29  2A  2B  2C  2D  2E  2F    30  31  32  33  34  35  36  37    38  39  3A  3B  3C  3D  3E  3F 
     0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    1,  1,  1,  1,  1,  1,  1,  1,    1,  1,  0,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________ 
 // 64  65  66  67  68  69  70  71    72  73  74  75  76  77  78  79    80  81  82  83  84  85  86  87    88  89  90  91  92  93  94  95   
 // 40  41  42  43  44  45  46  47    48  49  4A  4B  4C  4D  4E  4F    50  51  52  53  54  55  56  57    58  59  5A  5B  5C  5D  5E  5F 
     0,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________   
 // 96  97  98  99 100 101 102 103   104 105 106 107 108 109 110 111   112 113 114 115 116 117 118 119   120 121 122 123 124 125 126 127   
 // 60  61  62  63  64  65  66  67    68  69  6A  6B  6C  6D  6E  6F    70  71  72  73  74  75  76  77    78  79  7A  7B  7C  7D  7E  7F 
     0,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  1,  1,  1,  1,  1,    1,  1,  1,  0,  0,  0,  0,  0,
 //_____________________________________________________________________________________________________________________________________ 
 //128 129 130 131 132 133 134 135   136 137 138 139 140 141 142 143   144 145 146 147 148 149 150 151   152 153 154 155 156 157 158 159   
 // 80  81  82  83  84  85  86  87    88  89  8A  8B  8C  8D  8E  8F    90  91  92  93  94  95  96  97    98  99  9A  9B  9C  9D  9E  9F 
     0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________   
 //160 161 162 163 164 165 166 167   168 169 170 171 172 173 174 175   176 177 178 179 180 181 182 183   184 185 186 187 188 189 190 191   
 // A0  A1  A2  A3  A4  A5  A6  A7    A8  A9  AA  AB  AC  AD  AE  AF    B0  B1  B2  B3  B4  B5  B6  B7    B8  B9  BA  BB  BC  BD  BE  BF 
     0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________   
 //192 193 194 195 196 197 198 199   200 201 202 203 204 205 206 207   208 209 210 211 212 213 214 215   216 217 218 219 220 221 222 223   
 // C0  C1  C2  C3  C4  C5  C6  C7    C8  C9  CA  CB  CC  CD  CE  CF    D0  D1  D2  D3  D4  D5  D6  D7    D8  D9  DA  DB  DC  DD  DE  DF 
     0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,
 //_______________________________   _______________________________   _______________________________   _______________________________   
 //224 225 226 227 228 229 230 231   232 233 234 235 236 237 238 239   240 241 242 243 244 245 246 247   248 249 250 251 252 253 254 255   
 // E0  E1  E2  E3  E4  E5  E6  E7    E8  E9  EA  EB  EC  ED  EE  EF    F0  F1  F2  F3  F4  F5  F6  F7    F8  F9  FA  FB  FC  FD  FE  FF 
     0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0};
 //_____________________________________________________________________________________________________________________________________ 

/*
(winerror.h)
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define HRESULT_CODE(hr)    ((hr) &amp; 0xFFFF)
*/

//English Non-Unicode sayit for SAPI5
HRESULT sayit_sapi5(char* aSTRING)
  {
  char c;
  int x,y=0,cc=0;
  WCHAR* uniSTRING= NULL;
  ISpVoice* sapiVoice5= NULL;
  HRESULT hr=-1;
  //_______________________________________________________________
  //If first character is NULL?! Don't do anything!
  if(aSTRING==NULL) return hr; 
  if(aSTRING[0]=='\0') return hr; 
  //system("pause");

  //_______________________________________________________________
  //calculate string length and Count standard ASCII characters 
  // that should appear in valid ASCII/ANSI text.
  while(aSTRING[y]!='\0')
    {
    c=aSTRING[y]; 
    if(c==27) return hr; //Found [ESC] !!! Bail Out Quick!!!!
    y++;
    cc+=LettersNumbers[c];
    /*Lowercase Letters    [Most popular characters first]
    if(c=='e') {cc++; continue;}  // e - 11.1607%
    if(c=='a') {cc++; continue;}  // a - 8.4966%
    if(c=='r') {cc++; continue;}  // r - 7.5809%
    if(c=='i') {cc++; continue;}  // i - 7.5448%
    if(c=='o') {cc++; continue;}  // o - 7.1635%
    if(c=='t') {cc++; continue;}  // t - 6.9509%
    if(c=='n') {cc++; continue;}  // n - 6.6544%
    if(c=='s') {cc++; continue;}  // s - 5.7351%
    if(c=='l') {cc++; continue;}  // l - 5.4893%
    if(c=='c') {cc++; continue;}  // c - 4.5388%
    if(c=='u') {cc++; continue;}  // u - 3.6308%
    if(c=='d') {cc++; continue;}  // d - 3.3844%
    if(c=='p') {cc++; continue;}  // p - 3.1671%
    if(c=='m') {cc++; continue;}  // m - 3.0129%
    if(c=='h') {cc++; continue;}  // h - 3.0034%
    if(c=='g') {cc++; continue;}  // g - 2.4705%
    if(c=='b') {cc++; continue;}  // b - 2.0720%
    if(c=='f') {cc++; continue;}  // f - 1.8121%
    if(c=='y') {cc++; continue;}  // y - 1.7779%
    if(c=='w') {cc++; continue;}  // w - 1.2899%
    if(c=='k') {cc++; continue;}  // k - 1.1016%
    if(c=='v') {cc++; continue;}  // v - 1.0074%
    if(c=='x') {cc++; continue;}  // x - 0.2902%
    if(c=='z') {cc++; continue;}  // z - 0.2722%
    if(c=='j') {cc++; continue;}  // j - 0.1965%
    if(c=='q') {cc++; continue;}  // q - 0.1962%     
    //Uppercase Letters
    if(c=='E') {cc++; continue;}  // E - 11.1607%
    if(c=='A') {cc++; continue;}  // A - 8.4966%
    if(c=='R') {cc++; continue;}  // R - 7.5809%
    if(c=='I') {cc++; continue;}  // I - 7.5448%
    if(c=='O') {cc++; continue;}  // O - 7.1635%
    if(c=='T') {cc++; continue;}  // T - 6.9509%
    if(c=='N') {cc++; continue;}  // N - 6.6544%
    if(c=='S') {cc++; continue;}  // S - 5.7351%
    if(c=='L') {cc++; continue;}  // L - 5.4893%
    if(c=='C') {cc++; continue;}  // C - 4.5388%
    if(c=='U') {cc++; continue;}  // U - 3.6308%
    if(c=='D') {cc++; continue;}  // D - 3.3844%
    if(c=='P') {cc++; continue;}  // P - 3.1671%
    if(c=='M') {cc++; continue;}  // M - 3.0129%
    if(c=='H') {cc++; continue;}  // H - 3.0034%
    if(c=='G') {cc++; continue;}  // G - 2.4705%
    if(c=='B') {cc++; continue;}  // B - 2.0720%
    if(c=='F') {cc++; continue;}  // F - 1.8121%
    if(c=='Y') {cc++; continue;}  // Y - 1.7779%
    if(c=='W') {cc++; continue;}  // W - 1.2899%
    if(c=='K') {cc++; continue;}  // K - 1.1016%
    if(c=='V') {cc++; continue;}  // V - 1.0074%
    if(c=='X') {cc++; continue;}  // X - 0.2902%
    if(c=='Z') {cc++; continue;}  // Z - 0.2722%
    if(c=='J') {cc++; continue;}  // J - 0.1965%
    if(c=='Q') {cc++; continue;}  // Q - 0.1962%
    //Digits
    if(c=='7') {cc++; continue;}  // 7 - 9.7%
    if(c=='3') {cc++; continue;}  // 3 - 7.5%
    if(c=='8') {cc++; continue;}  // 8 - 6.7%
    if(c=='4') {cc++; continue;}  // 4 - 5.6%
    if(c=='5') {cc++; continue;}  // 5 - 5.1%
    if(c=='9') {cc++; continue;}  // 9 - 4.8%
    if(c=='6') {cc++; continue;}  // 6 - 3.4%
    if(c=='2') {cc++; continue;}  // 2 - 3.4%
    if(c=='1') {cc++; continue;}  // 1 - 1.2%
    if(c=='0') {cc++; continue;}  // 0 - 1.0% */
    }
  if(cc<1) return hr; //Didn't find any ASCII/ANSI text characters!! Don't do anything!
  if(y<1) return hr;  //No text! Don't do anything! 

  //_______________________________________________________________
  //Speak qualified speech 
  hr=CoInitialize(NULL);
  if(SUCCEEDED(hr))
    {
    uniSTRING=(WCHAR*)calloc((y+32),sizeof(WCHAR));
    if(uniSTRING!=NULL)
      {
      //_____________________________________________________
      //Condition the string and copy aSTRING into uniSTRING
      for(x=0;x<y;x++)
        {
        c=aSTRING[x]; 
        if(c==0) break;
        else if(c<32) uniSTRING[x]=32; //filter out extraneous characters.
        else if(c=='|') uniSTRING[x]=32; //Don't say "Vertical Line"
        //Don't speak remaining characters of 3 or more in a row
        //else if((c=='-')||(c=='=')||(c=='*')||(c=='_'))
        else //ALL remaining characters
          {
          if(aSTRING[x+1]==c)
            {
            if(aSTRING[x+2]==c)
              {
              while(aSTRING[x]==c){uniSTRING[x]=32; x++;}
              continue;
              }
            }
          }
          
        // Else copy all other characters directly
        uniSTRING[x]=c;
        }
      //_____________________________________________________
      //Talk
      hr = CoCreateInstance(CLSID_SpVoice,NULL,CLSCTX_ALL,IID_ISpVoice,(void**)&sapiVoice5);
      if(SUCCEEDED(hr))
        {
        hr = sapiVoice5->Speak(&uniSTRING[0], SPF_DEFAULT,NULL); //or SPF_ASYNC //SPF_DEFAULT
        sapiVoice5->Release();
        sapiVoice5 = NULL;
        }
      }
    CoUninitialize();
    free(uniSTRING);
    }
  return hr;
  }
 
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
   {
   sayit_sapi5(lpCmdLine);
   return 0;
   }       
