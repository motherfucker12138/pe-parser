#include<windows.h>
#include<TChar.h>
#include<iostream>
#include<time.h>
#include<string>

#include <stdlib.h>

#include<fstream>
#include <io.h>
#include <fcntl.h>
#define _ui unsigned int
 #define _ul unsigned long
//int wmain(int argc, wchar_t* argv[])
//{
//#define ____DEBUG
//  #define _qunimade
#ifdef ____DEBUG

#define FUCK(_format, _var) printf(_format, _var);
#define CUM(_str) printf(_str);
#else
#define FUCK(_format, _var);
#define CUM(_str);
#endif

#ifdef _qunimade
#define qnmd return 0
#else
#define qnmd while(1)break
#endif // _UNICODE
#ifdef _UNICODE

#define cout(x) std::wcout<<_TEXT(##x##)
#define pout(x) std::wcout<<##x
#define acout(x) std::cout<<##x
#define motherfucker_string std::wstring
#else
#define cout(x) std::cout<<##x
#define acout(x) std::cout<<##x
#define pout(x) std::cout<<##x
#define motherfucker_string std::string
#endif // _UNICODE
#pragma comment(lib,"user32.lib")
#include <map>

void _read_ascii(_ui _offset, std::ifstream* _steam, char* _out) {
    char hex_sting[4096] = {0};
    char buffer[64];
    for(int i=0;;i++){
        memset(buffer,0,64);
        _steam->seekg(_offset+i);
        _steam->read(buffer, 1);
        FUCK("%u\n",(unsigned char)buffer[0]);
        strcat(hex_sting,buffer);
        if(strlen(buffer)==0)
            break;
    }
    strcpy(_out, hex_sting);
}


_ui _2_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[4+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    return (_ui)strtoul(hex_sting,NULL,16);
}

_ui _4_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[8+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    FUCK("hex_sting: %s",hex_sting);
    return (_ui)strtoul(hex_sting,NULL,16);
}


// ����һ���ṹ�壬�������section header
typedef unsigned short WORD;
typedef unsigned long DWORD;
struct SECTION_HEADER_STRUCT {
    DWORD name_high;
    DWORD name_low;
    DWORD virtual_size;
    DWORD virtual_address;
    DWORD size_of_raw_data;
    DWORD pointer_to_raw_data;
    DWORD pointer_to_relocations;
    DWORD pointer_to_linenumbers;
    WORD number_of_relocations;
    WORD number_of_linenumbers;
    DWORD flag;
} section_header, *p_section_header;

void flag_display(std::map<_ui, motherfucker_string> fucking_map, _ui flag_value) {
    cout("������������˵ı�־λ��\n");
    std::map<_ui, motherfucker_string>::iterator iter;
    iter = fucking_map.begin();
    while(iter != fucking_map.end()) {
        _ui fuckyou=flag_value&(iter->first);
        if(fuckyou>0){
            acout("\t");
            pout(iter->second);
            acout("\n");
        }
        iter++;
    }
}
struct DATA_DIRECTORY_STRUCT {
    DWORD addr;
    DWORD size;
} data_directory, *p_data_directory;
std::map<motherfucker_string, struct DATA_DIRECTORY_STRUCT> data_directory_map ;
_ui convert_rva_to_file_pointer(_ui rva, struct SECTION_HEADER_STRUCT* _p_section_header, _ui number_of_sections) {
    _ui time_stamp_umber_of_sections=rva;
    for(int i=0;i<number_of_sections;i++) {
        FUCK("section virtual address : 0x%0x\n",_p_section_header[i].virtual_address);
        FUCK("section raw file pointer: 0x%0x\n",_p_section_header[i].pointer_to_raw_data);
        _ui fuckyou = _p_section_header[i].virtual_address + _p_section_header[i].virtual_size;
        FUCK("fuckyou: 0x%x\n",fuckyou);
        if(fuckyou >= time_stamp_umber_of_sections) {
            // cout("С��������ô���£�\n");
            // cout("С��������ô���£�\n");
            FUCK("0x%x\n",time_stamp_umber_of_sections);
            // cout("С��������ô���£�\n");
            FUCK("0x%x\n",_p_section_header[i].virtual_address);
            FUCK("%x\n",(_ui)_p_section_header[i].virtual_address);
            FUCK("%x\n", _p_section_header[i].pointer_to_raw_data);
            return time_stamp_umber_of_sections - _p_section_header[i].virtual_address+_p_section_header[i].pointer_to_raw_data;
        }
    }
}

int _tmain(int argc, TCHAR *argv[]){
	*stdout = *fopen("motherfuckerout.txt","w"); 
    // LPCTSTR _fucking_final_name = _TEXT("C:\\users\\public\\downloads\\Final.gif");
    // CopyFile(argv[1],"",0)
    
    std::map<_ui, std::string> machine_type_my_map ;

machine_type_my_map.insert(std::pair<_ui,std::string>(0x8664,"IMAGE_FILE_MACHINE_AMD64"));
    //�ҵ��Ե�cmd���ǰ�������������룬������ִ��֮ǰ����ִ��һ��chcp�������������������
	// �����������ĵ����ϣ�chcp 936����invalid page����ô�������Ҫ�޸�һЩ����
	// https://social.msdn.microsoft.com/Forums/ie/zh-TW/61f4f0bc-b7d6-4010-a4a9-2359cd2b9991/invalid-code-page?forum=237
	// https://ibb.co/KVnkzJc
 system("chcp 936");    //LPCTSTR szError = "���ڿ۵�";
 SetConsoleTitle(L"My Console Window - ���");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char* a = setlocale(LC_ALL, "chinese");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	// ��ʱascii�ᱻ����ascii���б���
	/*��*
	 error C2440: 'initializing' : cannot convert from 'const wchar_t [5]' to 'LPCTSTR'
	 ���Կ����������ˣ�˵���޷������ֽ��ַ�����ת����LPCTSTR
	 ŶŶŶ��sorry�������˱����ļ��ˣ����ʱ�����Ӧ�ò��ᱨ��ģ���Ϊ��û�ж���UNICODE��
	  error C2440: 'initializing' : cannot convert from 'const char [6]' to 'LPCTSTR'
	  ���Կ���������������֮�ڵı�������˵��û�а취��ascii�ַ���ת����unicode�ַ���
	  ��Ϊ��ʱ�����ǵ�LPCTSTR����UNICODE��ĳ��֣��Ѿ������LPCWSTR,
	  ��ʱ����������������Ǿ���Ҫ��ʽ�ظ��߱�����������ַ�����һ��UNICODE�ַ���
	  ����ʹ��  L
	  : error C2440: 'initializing' : cannot convert from 'const wchar_t [6]' to 'LPCTSTR'
	  ���Կ������ֱ����ˣ��������Ϊû����UNICODE�꣬LPCTSTR����� charָ�룬������wchar��
	  ����ʱ��ʹ����L�����ַ���Ӧ����UNICODE�ַ�������wchar����˾ͳ����˴�����ʵ�����޷���wcharת����char
	  �Ǹ���ν���أ�

	  �𰸾���ʹ��_TEXT
	  �����Ը���UNICODE�Ƿ������ж��Ƿ�ʹ��L
	  ��ʵ_TEXT�Ķ������
	  #ifdef UNICODE
	  typedef _TEXT(x) L ## x
	  #else
	  typedef _TEXT(x) x
	#endif
	�������������
	*/
//	LPCTSTR szError = _TEXT("���ڿ۵�");

//    MessageBox(NULL, szError, NULL, 0);

//LPCTSTR pszName = _TEXT("Path");
//TCHAR pszValue[4096] = {0};
//GetEnvironmentVariable(pszName, pszValue, 4096);
////std::wcout << pszValue;
////printf("%s\n", pszValue);
//cout(pszValue);
//������дһ��PE Parser
//���ܾ��Ƕ�PE�ļ����н��������������θ���������
//����֮ǰ��PE��ʽ���˽⣬���·�Ϊ���¼�������
//DOS header
//dos stub
//NT header
////section
//�õģ�����Ϳ�ʼߣ
//����Ҫ��ȡ�ļ������һ�Ҫ�Զ����Ƶ���ʽ��ȡ�ļ�

//�������������һ��PE��ʽ��ر�׼��pdf   http://www.osdever.net/documents/PECOFF.pdf
//    ������һЩ�����ĸ���
//
//    image file ����������Ǿ����ļ�����ʵ���ǿ�ִ���ļ���exe dll sys�ȵ�
//    ֮���Խ��������ļ�����Ϊ������ļ��������ڴ�ľ���һ����
//    ����һ����������ǲ�����Ϊ��ִ���ļ�������Ϊ��ִ���ļ�һ��ָexe��׺���ļ�
//    ��������һ���ļ���Ȼ������ֱ��ִ�У���Ҳ��PE��ʽ�ģ�ͳ��Ϊimage file�����ļ�
//
//    Object file������ʹ��cl���������������һ���ļ���һ��Ҫ������������������ԣ���������ļ�
//    ������������еĶ���û���κι�ϵ
//    object file��linnker�����������������ļ���linker����������ӳ�image file����һ����exe��
//
//    RVA  ��������ַ��������������ַ��һ����ַ����Ե���image base
//    image base��ַ��VA��Ҳ���Ǿ��������ַ������˵image base��0x4000,��ôRVA=0x100�������VA����0x4100
//
//    VA  ���ö�����ˣ������Ѿ�˵���ˣ�ֻ������һ�㣬����VA��ֵ����һ��׼ȷ����Ϊ��ʱ��û�м��ص��ڴ��У�
//    ����ϵͳָ�������image���ص��ĸ��ڴ��ַ��
//
//    file pointer��������VA��RVA��ֻ����VA��RVA������ڴ���Եĵ�ַ��file ponter����Դ����ļ����Ե�
//    ��ʵ˵���˶�������ƫ�����Ķ���
//
//    time stamp ʱ�����ûʲô��˵��
//
//    section   �����е���8086����е�segment���Σ�
//
//    һ������32λPE�ṹͼ
//    https://ibb.co/rshJqNr

//���PDF��ı�׼��һ���ֶ��ˣ������ˣ�����������һ����
//https://formats.kaitai.io/microsoft_pe/microsoft_pe.svg
//    ���svg�汾��ͦ�����
//    ֱ�����������򿪲鿴������
//��ߣ��
//�Ȱ�PE�ļ�����һ��buffer��
//std::ifstream input( "C:\\Final.gif", std::ios::binary );
//
//    // copies all data into buffer
//    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
char buffer[64] = {0};
std::ifstream strm;
strm.open (argv[1],std::ifstream::binary);
// strm.open ( _TEXT("C:\\Users\\x\\Documents\\Visual Studio 2012\\Projects\\ConsoleApplication1\\ConsoleApplication1\\ConsoleApplication1.exe") );

strm.seekg (0);
strm.read (buffer, 2);
//cout((unsigned char)buffer[60]);
//cout(_TEXT("Hello�� Worn\n"));
//cout(_TEXT("Hello�� Worn\n"));
// MessageBox(NULL, _TEXT("��Ÿ�ڿ�"), NULL, 0);//������magic�ַ�����Ҳ����MZ�������ֽ�
//cout(_TEXT("����������Ͳ���һ��PE�ļ�\n"));

if(buffer[0]!='M' && buffer[1] != 'Z') {
    cout("����������Ͳ���һ��PE�ļ�\n");
}
else{
    cout("��⵽ħ���ַ�MZ��������һ��PE�ļ�����������������\n");
}
//ֱ���Թ�58�ֽڣ���Ϊ��Щ��Ϊ��dosϵͳ���ݵ�һЩ������������ûɶ�ã�����
strm.seekg (60);
//ͨ������ƫ��������������58�ֽڣ�Ȼ�������ٶ�ȡ����4���ֽڣ�����ȡPE header��ƫ����
//����NT header
memset(buffer,0,64);
strm.read (buffer, 4);
//����С�����ԭ��������Ҫ�����ĸ��ֽڽ��з���
char  _tmnp_string[2+1]={0};
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
char* hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
cout("��λ��PE headerƫ����Ϊ�� ");
//acout(hex_sting);acout("\n");
_ui pe_header_offset=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
printf("0x%08x\n", pe_header_offset);

//Ȼ�����ǰ��ļ�ָ�붨λ��pe_header_offset
//��λ�ú��ȶ�ȡ��4�ֽڵ�peǩ��������PE\0\0
strm.seekg (pe_header_offset);
memset(buffer,0,64);
strm.read (buffer, 4);
cout("PEǩ����");acout(buffer);acout("\n");
//Ȼ����20���ֽڵ�coff header��COFF header������˺ܶ���Ҫ����Ϣ
//��PEbear���棬coff header������ file header
//������machine type 2bytes
//machine type�������б�
/*��*
Constant	Value	Description
IMAGE_FILE_MACHINE_UNKNOWN
0x0
The content of this field is assumed to be applicable to any machine type
IMAGE_FILE_MACHINE_AM33
0x1d3
Matsushita AM33
IMAGE_FILE_MACHINE_AMD64
0x8664
x64
IMAGE_FILE_MACHINE_ARM
0x1c0
ARM little endian
IMAGE_FILE_MACHINE_ARM64
0xaa64
ARM64 little endian
IMAGE_FILE_MACHINE_ARMNT
0x1c4
ARM Thumb-2 little endian
IMAGE_FILE_MACHINE_EBC
0xebc
EFI byte code
IMAGE_FILE_MACHINE_I386
0x14c
Intel 386 or later processors and compatible processors
IMAGE_FILE_MACHINE_IA64
0x200
Intel Itanium processor family
IMAGE_FILE_MACHINE_LOONGARCH32
0x6232
LoongArch 32-bit processor family
IMAGE_FILE_MACHINE_LOONGARCH64
0x6264
LoongArch 64-bit processor family
IMAGE_FILE_MACHINE_M32R
0x9041
Mitsubishi M32R little endian
IMAGE_FILE_MACHINE_MIPS16
0x266
MIPS16
IMAGE_FILE_MACHINE_MIPSFPU
0x366
MIPS with FPU
IMAGE_FILE_MACHINE_MIPSFPU16
0x466
MIPS16 with FPU
IMAGE_FILE_MACHINE_POWERPC
0x1f0
Power PC little endian
IMAGE_FILE_MACHINE_POWERPCFP
0x1f1
Power PC with floating point support
IMAGE_FILE_MACHINE_R4000
0x166
MIPS little endian
IMAGE_FILE_MACHINE_RISCV32
0x5032
RISC-V 32-bit address space
IMAGE_FILE_MACHINE_RISCV64
0x5064
RISC-V 64-bit address space
IMAGE_FILE_MACHINE_RISCV128
0x5128
RISC-V 128-bit address space
IMAGE_FILE_MACHINE_SH3
0x1a2
Hitachi SH3
IMAGE_FILE_MACHINE_SH3DSP
0x1a3
Hitachi SH3 DSP
IMAGE_FILE_MACHINE_SH4
0x1a6
Hitachi SH4
IMAGE_FILE_MACHINE_SH5
0x1a8
Hitachi SH5
IMAGE_FILE_MACHINE_THUMB
0x1c2
Thumb
IMAGE_FILE_MACHINE_WCEMIPSV2
0x169
MIPS little-endian WCE v2
*/
strm.seekg (pe_header_offset+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//ͬ����Ҫ���з�ת С����

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);

_ui machine_type_value=(_ui)strtoul(hex_sting,NULL,16);cout("machine type(������)��");
acout(machine_type_value);acout("    ");
free(hex_sting);
acout(machine_type_my_map[machine_type_value]);acout("\n");
//Ȼ����number of sections������������  2bytes
_ui number_of_sections;
strm.seekg (pe_header_offset+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//ͬ����Ҫ���з�ת С����

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
number_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
// _ui section_number = number_of_sections;
free(hex_sting);
cout("����������");
acout(number_of_sections);acout("\n");
//������ʱ������������ʱ�����˭��ʱ�����PE�ļ�����   4bytes

// ���˹ٷ��ĵ������ʱ�����link��ʱ�����Ҳ����exe���ɵ�ʱ�䣬���ǲ�֪��ΪɶϵͳPE�ļ���ʱ�������ǧ��ٹֵģ�
//��ʾ����δ����ʱ��
_ui time_stamp_umber_of_sections;
strm.seekg (pe_header_offset+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//ͬ����Ҫ���з�ת С����

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
cout("PE�ļ�����ʱ�䣨link)��");
//acout(time_stamp_umber_of_sections);acout("\n");
//��*
//������һ�ζ�ʱ������д���
////////////////////////////////////////////////////////////
static const time_t default_time = 1230728833;
static const char default_format[] = "%a %b %d %Y";


        time_t rawtime =(time_t)time_stamp_umber_of_sections;
	struct tm timeinfo;
	char timebuf[26];

	errno_t error;
	error = localtime_s( &timeinfo,&rawtime );
	if (error)
	{
		printf("Invalid argument to _localtime64_s.");
		return(1);
	}

	error = asctime_s (timebuf,26,&timeinfo);
	if (error)
	{
		printf("Invalid argument to asctime_s.");
		return(1);
	}

	printf( "%s \n", timebuf );
////////////////////////////////////////////////////////////
////Ȼ���ٶ�ȡ4bytes��ȡ���ű��ƫ����

strm.seekg (pe_header_offset+4+2+2+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
cout("���ű�ƫ������symbol table)��");
//��������0���Ǿ���˵��û�з��ű�
printf("0x%08x\n",time_stamp_umber_of_sections);


//Ȼ���ٶ�ȡ4���ֽڣ���ȡ���ŵ�����
strm.seekg (pe_header_offset+4+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
cout("����������symbol number)��");printf("%d\n",time_stamp_umber_of_sections);

//�ٶ�ȡ2bytes��ȡoptional header��size
strm.seekg (pe_header_offset+4+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
cout("optional header size��");printf("%d\n",time_stamp_umber_of_sections);

//��Ȼ�����characteristic������һ�ѱ�־λ  2bytes
//������������characteristic�б�
/*
Flag    Value   Description
IMAGE_FILE_RELOCS_STRIPPED
0x0001
Image only, Windows CE, and Microsoft Windows NT and later. This indicates that the file does not contain base relocations and must therefore be loaded at its preferred base address. If the base address is not available, the loader reports an error. The default behavior of the linker is to strip base relocations from executable (EXE) files.
IMAGE_FILE_EXECUTABLE_IMAGE

0x0002
Image only. This indicates that the image file is valid and can be run. If this flag is not set, it indicates a linker error.
IMAGE_FILE_LINE_NUMS_STRIPPED
��������

0x0004
COFF line numbers have been removed. This flag is deprecated and should be zero.
IMAGE_FILE_LOCAL_SYMS_STRIPPED

0x0008
COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero.
IMAGE_FILE_AGGRESSIVE_WS_TRIM

0x0010
Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero.
IMAGE_FILE_LARGE_ADDRESS_ AWARE

0x0020
Application can handle > 2-GB addresses.

0x0040
This flag is reserved for future use.

IMAGE_FILE_BYTES_REVERSED_LO
0x0080
Little endian: the least significant bit (LSB) precedes the most significant bit (MSB) in memory. This flag is deprecated and should be zero.

IMAGE_FILE_32BIT_MACHINE
0x0100
Machine is based on a 32-bit-word architecture.
IMAGE_FILE_DEBUG_STRIPPED

0x0200
Debugging information is removed from the image file.
IMAGE_FILE_REMOVABLE_RUN_ FROM_SWAP
0x0400

If the image is on removable media, fully load it and copy it to the swap file.
IMAGE_FILE_NET_RUN_FROM_SWAP
0x0800
If the image is on network media, fully load it and copy it to the swap file.
IMAGE_FILE_SYSTEM
0x1000
The image file is a system file, not a user program.
IMAGE_FILE_DLL
0x2000
The image file is a dynamic-link library (DLL). Such files are considered executable files for almost all purposes, although they cannot be directly run.
IMAGE_FILE_UP_SYSTEM_ONLY
0x4000
The file should be run only on a uniprocessor machine.
IMAGE_FILE_BYTES_REVERSED_HI
0x8000
Big endian: the MSB precedes the LSB in memory. This flag is deprecated and should be zero.
*/

std::map<_ui, motherfucker_string> characteritics_flags_machine_type_my_map ;
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x2000,_TEXT("The image file is a dynamic-link library (DLL). Such files are considered executable files for almost all purposes, although they cannot be directly run.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x1000,_TEXT("The image file is a system file, not a user program.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0800,_TEXT("If the image is on network media, fully load it and copy it to the swap file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0400,_TEXT("If the image is on removable media, fully load it and copy it to the swap file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0200,_TEXT("Debugging information is removed from the image file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0100,_TEXT("Machine is based on a 32-bit-word architecture.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0001,_TEXT("Image only, Windows CE, and Microsoft Windows NT and later. This indicates that the file does not contain base relocations and must therefore be loaded at its preferred base address. If the base address is not available, the loader reports an error. The default behavior of the linker is to strip base relocations from executable (EXE) files.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0002,_TEXT("cao��������Image only. This indicates that the image file is valid and can be run. If this flag is not set, it indicates a linker error.�������ھ����ļ��������־λ�����˸þ����ļ��ǺϷ��ģ������������У���������־λû�����ã���˵����������������")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0004,_TEXT("COFF line numbers have been removed. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0008,_TEXT("COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0010,_TEXT("Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0020,_TEXT("Application can handle > 2-GB addresses.�˳����ܹ�����>2GB�ĵ�ַ")));
//IMAGE_FILE_BYTES_REVERSED_LO
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0040,_TEXT("This flag is reserved for future use.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0080,_TEXT("Little endian: the least significant bit (LSB) precedes the most significant bit (MSB) in memory. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x8000,_TEXT("Big endian: the MSB precedes the LSB in memory. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x4000,_TEXT("The file should be run only on a uniprocessor machine.")));
strm.seekg (pe_header_offset+4+2+2+4+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
cout("characteristic value��");printf("%d\n",time_stamp_umber_of_sections);
cout("������������˵ı�־λ��\n");
std::map<_ui, motherfucker_string>::iterator iter;
    iter = characteritics_flags_machine_type_my_map.begin();
    while(iter != characteritics_flags_machine_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections&(iter->first);
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("������\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }

//    ���ˣ���Щ����ȡ��Ϻ󣬾͸ö�ȡoptional header��

//ǰ�������Ѿ���ȡ����optional header �Ĵ�С
//�ڶ�ȡ�������coff header֮��optional header���ǽ����ŵ�

//�������svg�ϵ�˵����optional header���Ա���Ϊ������
//OptionalHeaderStd           std
//OptionalHeaderWindows           widnows
//OptionalHeaderDataDirs          datadirectory
//����Ϊʲô��ֳ������֣��ڹٷ��ĵ�https://docs.microsoft.com/en-us/windows/win32/debug/pe-format��ҳ��
 //    ctrl+f����The optional header itself has three major parts.�ͻ��ҵ���
//������������std����
//�����ֽڵ�format
cout("\n������������������������������������������������������������ʼ----OPTIONAL HEADER----��ʼ����������������������������������������������������������");acout("\n");
cout("==================================��ʼ----STD����----��ʼ==================================");acout("\n");
//2bytes��format����PEbear��format��Ӧ����magic���������Ǻ�pebear����һ��  �Ͼ�PEbear�Ǹ����֪���Ĺ���
// �ڹٷ��ĵ���Ҳ�ǳ���magic��������format
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(������)��");
free(hex_sting);
//��΢��ٷ��ĵ��У�magic��ֵһ������0x10b��Ӧ32bit  0x20b��Ӧ64bit
//���ֵ�����ȼ���machine typeҪ�ߣ�������߳���ì�ܣ�����magic��ֵΪ׼�������������������Ӧ����һ�µ�
cout("magic��");
_ui magic_numberrr = time_stamp_umber_of_sections;
if(time_stamp_umber_of_sections==0x10b)
    cout("PE32��Ҳ����32λ");
if(time_stamp_umber_of_sections==0x20b)
    cout("PE32+��Ҳ����64λ");
cout("\n");
//Ȼ����major linker version��minor linker version
//��֪��������������ɶ��
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
time_stamp_umber_of_sections=(_ui)strtoul(_tmnp_string,NULL,16);
cout("���������汾�ţ�");acout(time_stamp_umber_of_sections);acout("\n");
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
time_stamp_umber_of_sections=(_ui)strtoul(_tmnp_string,NULL,16);
cout("�������ΰ汾�ţ�");acout(time_stamp_umber_of_sections);acout("\n");
free(hex_sting);

//Ȼ����size_of_code������PE�ļ��д���Ĵ�С 4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("PE�ļ���.text�����Ĵ�С��");
acout(time_stamp_umber_of_sections);acout(" bytes\n");

//size_of_initialized_data����ʵ����.data����
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4);
memset(buffer,0,64);
FUCK("read return value %d\n",strm.read (buffer, 4));
strm.read (buffer, 4);
 int bytesRead = (int)strm.gcount();
FUCK("bytesRead %d\n",bytesRead);
FUCK("offset%x\n",pe_header_offset+4+2+2+4+4+4+2+2+2+2+4);
FUCK("buffer %s\n",buffer);
FUCK("buffer %d\n",buffer[3]);
FUCK("buffer %d\n",buffer[2]);
FUCK("buffer %d\n",buffer[1]);
FUCK("buffer %d\n",buffer[0]);
// qnmd;
time_stamp_umber_of_sections=_4_bytes_deal(buffer);

cout("PE�ļ���.data�����Ĵ�С��");
acout(time_stamp_umber_of_sections);acout(" bytes\n");
qnmd;

//size_of_uninitialized_data����ʵ����.bss����
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("PE�ļ���.bss�����Ĵ�С��");
acout(time_stamp_umber_of_sections);acout(" bytes\n");

//Ȼ����entrypoint   address_of_entry_point  4bytes
//�����һ����Ե�ַ����������ھ����ļ����ص��ڴ�֮���image base��ƫ����
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("entry point��RVA����ַ��");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");

//Ȼ����base_of_code��4bytes
// code��������ھ����ļ��������ڴ��image base��RVA
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("base of code��RVA����ַ��");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");

//���magic��ֵ��pe32����ô��base of code֮�󣬻���һ��base of data
//data���������image base��RVA
_ui seek_offset  = 0;
_ui image_bse_sizeof  = 8;
if(magic_numberrr==0x10b){
        seek_offset=4;
        image_bse_sizeof=4;
    strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("base of data��RVA����ַ��");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");
}
//�����std���־����ǽ�����
cout("\n==================================����----STD����----����==================================");acout("\n");



cout("\n==================================��ʼ----windows����----��ʼ==================================");acout("\n");


////image base,�����pe�ļ��������ڴ����ѡ��ַ��Ĭ����0x00400000
//��������ASLR���ƵĴ��ڣ������ַ�󲿷�����¶����ᱻӦ�ã���Ϊ�����Ѿ�����ĳ����ռ��
//��һ���ط�����Ҫ����pe32��pe32+��pe32ֻռ��4bytes��pe32+ռ��8bytes
//����ʹ�����涨���image_bse_sizeof
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//��ת
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("����64λ�԰ɣ�\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("��16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("image base��ַ��");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("image base��ַ��");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");
}
//Ȼ����section_alignment  4bytes
// ��������ڼ������ڴ�֮�󣬸��������������õģ�һ������£�����ֵ���ǵ�ǰ�������ܹ���һ��page�Ĵ�С
//page���ڴ��ҳ��ؼ���
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("section_alignment��");
printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");

// ������file alignment��Ĭ��ֵ��512  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("file _alignment��");
printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");

// �����ǲ���ϵͳ���汾�� 2bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("����ϵͳ���汾�ţ�");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");


// �����ǲ���ϵͳ�ΰ汾�� 2bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("����ϵͳ�ΰ汾�ţ�");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// �����ļ���汾�źʹΰ汾��
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("�����ļ����汾�ţ�");printf("%u ", time_stamp_umber_of_sections);
cout("\n");
hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("�����ļ��ΰ汾�ţ�");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");


// ��ϵͳ�����汾�źʹΰ汾��
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("��ϵͳ���汾�ţ�");printf("%u ", time_stamp_umber_of_sections);
cout("\n");
hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("��ϵͳ�ΰ汾�ţ�");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// ������
// win32_version_value  ����ֶ��Ǳ����ģ��������ֱ���ӹ�����
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
 
// size_of_image  image�������ڴ�֮��Ĵ�С����filealignment�ı���  4bytes
// ������ڴ����֮��Ĵ�С���Ǳ�ʵ�ʵ�image�ļ�Ҫ���
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("������ص��ڴ�֮��Ĵ�С��");printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");


// sizeofheader�����е�ͷ��������Ȼ������ȡ����file alignment�ı���

strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("header�ܴ�С������ȡ��filealignment����");printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");


// check_sum  �����ļ���У���
// ��У��͵ļ����㷨λ��IMAGHELP.DLL.

strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("checksum��");printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// 2bytes����ϵͳ��gui��cli��
// ����б�

std::map<_ui, motherfucker_string> characteritics_flags_machine_sub_ssytem_type_my_map ;
characteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(2,_TEXT("ͼ�λ���ϵͳ")));
characteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(3,_TEXT("�ַ��������У���ϵͳ")));
/*��*
Constant	Value	Description
IMAGE_SUBSYSTEM_UNKNOWN
0
An unknown subsystem
IMAGE_SUBSYSTEM_NATIVE
1
Device drivers and native Windows processes
IMAGE_SUBSYSTEM_WINDOWS_GUI
2
The Windows graphical user interface (GUI) subsystem
IMAGE_SUBSYSTEM_WINDOWS_CUI
3
The Windows character subsystem
IMAGE_SUBSYSTEM_OS2_CUI
5
The OS/2 character subsystem
IMAGE_SUBSYSTEM_POSIX_CUI
7
The Posix character subsystem
IMAGE_SUBSYSTEM_NATIVE_WINDOWS
8
Native Win9x driver
IMAGE_SUBSYSTEM_WINDOWS_CE_GUI
9
Windows CE
IMAGE_SUBSYSTEM_EFI_APPLICATION
10
An Extensible Firmware Interface (EFI) application
IMAGE_SUBSYSTEM_EFI_BOOT_ SERVICE_DRIVER
11
An EFI driver with boot services
IMAGE_SUBSYSTEM_EFI_RUNTIME_ DRIVER
12
An EFI driver with run-time services
IMAGE_SUBSYSTEM_EFI_ROM
13
An EFI ROM image
IMAGE_SUBSYSTEM_XBOX
14
XBOX
IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION
16
Windows boot application.
*��/*/
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);

sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("��ϵͳ��");cout("\n");
    iter = characteritics_flags_machine_sub_ssytem_type_my_map.begin();
    while(iter != characteritics_flags_machine_sub_ssytem_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections==iter->first;
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("������\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }

// dll_characteristics
// Ҳ��һ��flag
// �����б�����
std::map<_ui, motherfucker_string> dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map ;
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0040,_TEXT("DLL can be relocated at load time.DLL�ڼ��ص�ʱ����Ա����¶�λ")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0100,_TEXT("Image is NX compatible�� NX��Ϊno-execute��һ���ڴ汣����ʩ")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x4000,_TEXT("Image supports Control Flow Guard.�� ���CFG��������cl����ѡ����ָ�������ڵֿ��ڴ���©��")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x8000,_TEXT("Terminal Server aware.�Ҳ�֪�����������ʲô��˼")));
/*
Constant	Value	Description
0x0001
Reserved, must be zero.
0x0002
Reserved, must be zero.
0x0004
Reserved, must be zero.
0x0008
Reserved, must be zero.
IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA
0x0020
Image can handle a high entropy 64-bit virtual address space.
IMAGE_DLLCHARACTERISTICS_
DYNAMIC_BASE
0x0040
DLL can be relocated at load time.
IMAGE_DLLCHARACTERISTICS_
FORCE_INTEGRITY
0x0080
Code Integrity checks are enforced.
IMAGE_DLLCHARACTERISTICS_
NX_COMPAT
0x0100
Image is NX compatible.
IMAGE_DLLCHARACTERISTICS_ NO_ISOLATION
0x0200
Isolation aware, but do not isolate the image.
IMAGE_DLLCHARACTERISTICS_ NO_SEH
0x0400
Does not use structured exception (SE) handling. No SE handler may be called in this image.
IMAGE_DLLCHARACTERISTICS_ NO_BIND
0x0800
Do not bind the image.
IMAGE_DLLCHARACTERISTICS_APPCONTAINER
0x1000
Image must execute in an AppContainer.
IMAGE_DLLCHARACTERISTICS_ WDM_DRIVER
0x2000
A WDM driver.
IMAGE_DLLCHARACTERISTICS_GUARD_CF
0x4000
Image supports Control Flow Guard.
IMAGE_DLLCHARACTERISTICS_ TERMINAL_SERVER_AWARE
0x8000
Terminal Server aware.
*/
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
      
           hex_sting = (char*)malloc(8+1);

sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("dll chacacteristic��");cout("\n");
    iter = dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.begin();
    while(iter != dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections&(iter->first);
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("������\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }


// size_of_stack_reserve_32
// ��������ط��Ҵ���https://stackoverflow.com/questions/1858053/when-does-the-stack-really-overflow
// ����ش��size_of_stack_reserve_32��SizeOfStackCommit�Ľ��ͻ��ǱȽ�͸����
// ������������������ջ�ڴ�ģ�����ǰ�����Ƶ��������ڴ棬�������Ƶ��������ڴ�
// ����ʹ�õ�ջ�ռ���������ڴ�ʱ���ͻῪʼʹ�������ڴ棬�����̣�ҳ������
//�������ֶ���pe32��pe32+������ǰ��ռ��4bytes������ռ��8bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//��ת
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("����64λ�԰ɣ�\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("��16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_stack_reserve_64��");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_stack_reserve_32��");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// commit size
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//��ת
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("����64λ�԰ɣ�\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("��16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_stack_commit_64��");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_stack_commit_32��");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}

// ������sizeofheaporeserver��commit���������stack����һ��
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//��ת
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("����64λ�԰ɣ�\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("��16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_heap_reserve_64��");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_heap_reserve_32��");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// commit
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//��ת
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("����64λ�԰ɣ�\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("��16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_heap_commit_64��");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_heap_commit_32��");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// �����£���4bytes��loader flag�������ֶΣ�ֱ���Թ�
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof);

// �����number_of_rva_and_sizes
//  data-directory ������ 4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//��ת
memset(_tmnp_string,0,3);



//        cout("����64λ�԰ɣ�\n");
    //    unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");


//cout("16�����ַ���");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("data directory������");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//��֪��Ϊʲô�����ҵ�64bit�ı������ǻᶪ��һ������ݱ��32bit��
//��Ϊ�����õ���32bit�ı���������Ҫ�޸�һ��build oiptions�����pre step�����������ű�Ӧ���ǡ�
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// �ҵ�������������ܾͲ�֧��64bit���������ҷ����ˣ��ֿ���ʾ����
printf("%u",time_stamp_umber_of_sections);acout("\n");


cout("\n==================================����----windows����----����==================================");acout("\n");

cout("\n==================================��ʼ----data directory����----��ʼ==================================");acout("\n");
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4);

// ������Ҫ������ȡ15��8�ֽ����ݣ�ÿһ��8�ֽ����ݶ���һ��data directory��������һ����ַ��size

char buffer2[15*8] = {0};
memset(buffer2,0,15*8);
strm.read (buffer2, 15*8);
//��ת
memset(_tmnp_string,0,3);

std::map<_ui, motherfucker_string> data_directory_characteritics_flags_machine_type_my_map ;
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0,_TEXT("export_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(1,_TEXT("import_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(2,_TEXT("resource_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(3,_TEXT("exception_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(4,_TEXT("certificate_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(5,_TEXT("base_relocation_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(6,_TEXT("debug")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(7,_TEXT("architecture")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(8,_TEXT("global_ptr")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(9,_TEXT("tls_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(10,_TEXT("load_config_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(11,_TEXT("bound_import")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(12,_TEXT("iat")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(13,_TEXT("delay_import_descriptor")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(14,_TEXT("clr_runtime_header")));





for(int i=0;i<15;i++){
    pout(data_directory_characteritics_flags_machine_type_my_map[i]);
    hex_sting = (char*)malloc(8+1);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+0]);
    strcat(hex_sting, _tmnp_string);
    time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
    free(hex_sting);
    cout("��\n\t");
    cout("��ַ��RVA����");
    printf("\t0x%08x\n",time_stamp_umber_of_sections);
    data_directory.addr = time_stamp_umber_of_sections;
    hex_sting = (char*)malloc(8+1);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+7]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+6]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+5]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+4]);
    strcat(hex_sting, _tmnp_string);
    time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
    free(hex_sting);
    data_directory.size = time_stamp_umber_of_sections;
    cout("\t");
    cout("size��");
    printf("\t\t%u bytes\n\n",time_stamp_umber_of_sections);
    data_directory_map.insert(std::pair<motherfucker_string, struct DATA_DIRECTORY_STRUCT>(data_directory_characteritics_flags_machine_type_my_map[i], data_directory));
}

FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);

cout("\n==================================����----data directory����----����==================================");acout("\n");
cout("\n��������������������������������������������������������������----OPTIONAL HEADER----��������������������������������������������������������������");acout("\n");

// ��������seciton ����
cout("\n��������������������������������������������������������ʼ----SECTION HEADERs----��ʼ������������������������������������������������������");acout("\n");
// ���ڴ���file alignment�����ļ����룬�ڿ�ʼ������һ���ֵ�ʱ��ģ���Ҫ����ʱ��ƫ�����Ƿ���file alignment�ı���
// ��ǰ��ƫ������pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8



// section��parse����ͨ��ѭ�������
// ����8bytres��name
// ע������optional header��datadirectory �����һ��8bytes����λ
_ui section_offset_counter = 0;
p_section_header = (struct SECTION_HEADER_STRUCT*)malloc(number_of_sections);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
while(number_of_sections>(section_offset_counter/40)){
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 8);
char _tmnp_string2[1+1]={0};
hex_sting = (char*)malloc(8+1);
char* for_dword_string = (char*)malloc(8+1);
sprintf(_tmnp_string2,"%c",buffer[0]);
strcpy(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[0]);
strcpy(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[1]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[1]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[2]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[2]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[3]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[3]);
strcat(for_dword_string, _tmnp_string);
p_section_header[section_offset_counter/40].name_high=(DWORD)strtoul(for_dword_string,NULL,16);
free(for_dword_string);
for_dword_string = (char*)malloc(8+1);
sprintf(_tmnp_string2,"%c",buffer[4]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[4]);
strcpy(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[5]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[5]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[6]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[6]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[7]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[7]);
strcat(for_dword_string, _tmnp_string);
p_section_header[section_offset_counter/40].name_low=(DWORD)strtoul(for_dword_string,NULL,16);
free(for_dword_string);
cout("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n����(section)m���ƣ�");
pout(hex_sting);cout("\n");
free(hex_sting);

// virtual_size  4bytes
// �������ڴ��еĴ�С��ͬ������Ϊ�����ڴ���룬����raw size�ͽ����ڴ�֮���size���ڲ���
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);

time_stamp_umber_of_sections = _4_bytes_deal(buffer);

p_section_header[section_offset_counter/40].virtual_size = time_stamp_umber_of_sections;
cout("virtual size��");
printf("%u bytes\n", time_stamp_umber_of_sections);

// virtual_address  RVA   4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].virtual_address = time_stamp_umber_of_sections;
cout("virtual_address��RVA����");
printf("0x%08x\n", time_stamp_umber_of_sections);

// size_of_raw_data  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].size_of_raw_data = time_stamp_umber_of_sections;
cout("size_of_raw_data��");
printf("%u bytes\n", time_stamp_umber_of_sections);

// pointer_to_raw_data  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_raw_data = time_stamp_umber_of_sections;
cout("pointer_to_raw_data����PE�ļ��еĵ�ַ����");
printf("0x%08x\n", time_stamp_umber_of_sections);

// pointer_to_relocations  4bytes
// ����ֶζ��ڿ�ִ���ļ�û�����壬����Ϊ0�����Ƕ���dll���ļ���������ģ��������������ʵʵ������ֵ������
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);



time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_relocations = time_stamp_umber_of_sections;
cout("pointer_to_relocations��");
printf("0x%08x\n", time_stamp_umber_of_sections);

// pointer_to_relocations  4bytes
// ����ֶζ��ڿ�ִ���ļ�û�����壬����Ϊ0�����Ƕ���dll���ļ���������ģ��������������ʵʵ������ֵ������
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_linenumbers = time_stamp_umber_of_sections;
cout("pointer_to_linenumbers��");
printf("0x%08x\n", time_stamp_umber_of_sections);

FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
// number_of_relocations
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 2);
time_stamp_umber_of_sections = _2_bytes_deal(buffer);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
p_section_header[section_offset_counter/40].number_of_relocations = (WORD)time_stamp_umber_of_sections;
// �����Ƿ�����ջ��������԰ѱ������ڶ���
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
cout("number_of_relocations��");
printf("0x%08x\n", time_stamp_umber_of_sections);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
// number_of_linenumbers
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+2+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 2);
time_stamp_umber_of_sections = _2_bytes_deal(buffer);
p_section_header[section_offset_counter/40].number_of_linenumbers = (WORD)time_stamp_umber_of_sections;
cout("number_of_linenumbers��");
printf("0x%08x\n", time_stamp_umber_of_sections);
// characteristics  ����һ��flag
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+2+2+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].flag = time_stamp_umber_of_sections;
std::map<_ui, motherfucker_string> section_characteritics_flags_machine_type_my_map ;
// �����б�ο�΢��ٷ��ĵ�https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#section-flags
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000001,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000002,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000004,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000008,_TEXT("The section should not be padded to the next boundary. This flag is obsolete and is replaced by This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000010,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000020,_TEXT("The section contains executable code.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000040,_TEXT("The section contains initialized data.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000080,_TEXT("The section contains uninitialized data.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000100,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000200,_TEXT("The section contains comments or other information. The .drectve section has this type. This is valid for object files only.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000400,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000800,_TEXT("The section will not become part of the image. This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00001000,_TEXT("The section contains COMDAT data. For more information, see [COMDAT Sections (Object Only)](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#comdat-sections-object-only). This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00008000,_TEXT("The section contains data referenced through the global pointer (GP).")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00020000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00020000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00040000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00080000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00100000,_TEXT("Align data on a 1-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00200000,_TEXT("Align data on a 2-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00300000,_TEXT("Align data on a 4-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00400000,_TEXT("Align data on an 8-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00500000,_TEXT("Align data on a 16-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00600000,_TEXT("Align data on a 32-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00700000,_TEXT("Align data on a 64-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00800000,_TEXT("Align data on a 128-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00900000,_TEXT("Align data on a 256-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00A00000,_TEXT("Align data on a 512-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00B00000,_TEXT("Align data on a 1024-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00C00000,_TEXT("Align data on a 2048-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00D00000,_TEXT("Align data on a 4096-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00E00000,_TEXT("Align data on an 8192-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x01000000,_TEXT("The section contains extended relocations.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x02000000,_TEXT("The section can be discarded as needed.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x04000000,_TEXT("The section cannot be cached.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x08000000,_TEXT("The section is not pageable.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x10000000,_TEXT("The section can be shared in memory.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x20000000,_TEXT("The section can be executed as code.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x40000000,_TEXT("The section can be read.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x80000000,_TEXT("The section can be written to.")));
cout("������section��characteristic flag��\n\t");
flag_display(section_characteritics_flags_machine_type_my_map,time_stamp_umber_of_sections);
section_offset_counter+=40;acout("\n");
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
}
cout("\n����������������������������������������������������������----SECTION HEADERs----����������������������������������������������������������");acout("\n");

// ���������Ҫ�����е�һ����data directory���н���
// ������import directory
// ���ʽ���£�https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#the-idata-section
// ֮ǰ����Ҳ�Ѿ������ˣ�rva��raw addr��ת������
// ��Ҫsection jheader�е�һЩ�������������ǽ����ж�

// �Ȼ�ȡ��import directory��ƫ����
_ui raw_offset = 0;
FUCK("import table RVA: 0x%0x\n",data_directory_map[_TEXT("import_table")].addr);
for(int i=0;i<number_of_sections;i++) {
    FUCK("section virtual address : 0x%0x\n",p_section_header[i].virtual_address);
    FUCK("section raw file pointer: 0x%0x\n",p_section_header[i].pointer_to_raw_data);
    _ui fuckyou = p_section_header[i].virtual_address + p_section_header[i].virtual_size;
    FUCK("fuckyou: 0x%x\n",fuckyou);
    if(fuckyou >= data_directory_map[_TEXT("import_table")].addr) {
        raw_offset =    data_directory_map[_TEXT("import_table")].addr- p_section_header[i].virtual_address+p_section_header[i].pointer_to_raw_data;break;
    }
}
FUCK("raw offset disk addr 0x%08x", raw_offset);
// ��������ֻ��Ҫʹ��seek���ܶ�λ���ļ���import table��λ��
cout("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@��ʼ----����data directory----��ʼ@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");acout("\n");



// ��ʵimport tableҲ��ӵ�ж����ģ���Ҫѭ����ȡ��������־�������ȡ������20���ֽ�ȫΪ��
// �����Ҳ���д�ˣ���Ϊһ��ʼд�����ʱ������кúù滮������д����ǧ���У������ع��ͱ�Ҫ�鷳��
// ��Ҫ�����ܹ�������v���������
_ui _boss_break_flag=0;
_ui _boss_up_value = raw_offset;
while(1){
    strm.seekg (raw_offset);
memset(buffer,0,64);
strm.read(buffer, 20);

  for(int i=0;i<20;i++) {
            _boss_break_flag = 0;
            unsigned char _asd = 0;
            _asd = (unsigned char)buffer[i];
            if(_asd > 0) {break;}
            if(i+2>20) _boss_break_flag = 1;
        }
        if(_boss_break_flag>0) break;
strm.seekg (raw_offset);
memset(buffer,0,64);
strm.read(buffer, 4);
cout("--------------------------import table");

// Import Lookup Table RVA 4bytes
// ����ֶδ洢����lookp uptable��rva
time_stamp_umber_of_sections= _4_bytes_deal(buffer);
_ui _ila_rva = time_stamp_umber_of_sections;
cout("\n\tImport Lookup Table RVA��");
printf("0x%x\n",time_stamp_umber_of_sections);
// 4bytes ʱ���
strm.seekg (raw_offset+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tʱ�����");
int _is_bound = time_stamp_umber_of_sections;
printf("0x%x\n",time_stamp_umber_of_sections);

// forward chain������һ���ʱ���˽��Ǹ�ʲô����
strm.seekg (raw_offset+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tforward chain��");
printf("0x%x\n",time_stamp_umber_of_sections);


// Name RVA
strm.seekg (raw_offset+4+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tDLL name address(RVA)��");
printf("0x%x\n",time_stamp_umber_of_sections);
// ͨ��name addr rva��ȡ��dll���û���
// ͨ��rva��ȡfile pointer�ķ�ʽ�������һ�������ҾͰ���һ���ִ�����д�Ǻ�����
// ���ˣ�����д�ˣ�ֱ��д����������
// ջ��������ˣ���Ϊ�Ұ����ж�����д��main�������ˣ��о�Ҫ��ը�˶�
// һ�㶫�����䲻������
_ui name_raw_offset;
for(int i=0;i<number_of_sections;i++) {
    FUCK("section virtual address : 0x%0x\n",p_section_header[i].virtual_address);
    FUCK("section raw file pointer: 0x%0x\n",p_section_header[i].pointer_to_raw_data);
    _ui fuckyou = p_section_header[i].virtual_address + p_section_header[i].virtual_size;
    FUCK("fuckyou: 0x%x\n",fuckyou);
    if(fuckyou >= time_stamp_umber_of_sections) {
        cout("С��������ô���£�\n");
        cout("С��������ô���£�\n");
        FUCK("0x%x\n",time_stamp_umber_of_sections);
        cout("С��������ô���£�\n");
         FUCK("0x%x\n",p_section_header[i].virtual_address);
        FUCK("%x\n",(_ui)p_section_header[i].virtual_address);
        FUCK("%x\n", p_section_header[i].pointer_to_raw_data);
     name_raw_offset =   time_stamp_umber_of_sections - p_section_header[i].virtual_address+p_section_header[i].pointer_to_raw_data;
        break;
    }
}
        FUCK("name_raw_offset  %x\n", name_raw_offset);
         FUCK("name_raw_offset  %x\n", name_raw_offset);
// dll���֣���������û������unicode������������ֱ�ӵ���ascii���н���
hex_sting =(char*)malloc(4096);
memset(hex_sting,0,4096);

  FUCK("name_raw_offset  %x\n", name_raw_offset);
for(int i=0;;i++){
    memset(buffer,0,64);
    strm.seekg (name_raw_offset+i);
    strm.read(buffer, 1);
    FUCK("%u\n",(unsigned char)buffer[0]);
    strcat(hex_sting,buffer);
    if(strlen(buffer)==0)break;
   
}

cout("DLL�������ǣ�");
pout(hex_sting);cout("\n");
free(hex_sting);


// Import Address Table RVA (Thunk Table)
strm.seekg (raw_offset+4+4+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tImport Address Table RVA��");
printf("0x%x\n",time_stamp_umber_of_sections);

// Import Lookup Table RVA��Import Address Table RVA��ָ��Ľṹ��һ����
// ֻ�е�file��bound��ʱ�򣬲Ż᲻һ�����Ҳ�֪�����bound��ɶ��˼
// �Ҳ����bound����ֵ���Ǿ�̬���룿���ǰ�DLL�Ϳ�ִ���ļ�Ū��һ���ˣ��������ڼ��ص�ʱ���ٽ�DLL�ĺ�����ַ��䵽IAT��
// �ڲ�bound������£�ILT��IAT��������һ����
// ������Ҳ�㲻���bound��ɶ��˼�ˣ���Ϊ���Լ��������PE���Ǿ�̬�����
// ���ڱ����ʱ��ʹ����/MT�����Ǿ�̬���룬����PE-bear������Ȼ��ʾunbound
// ���ǿ���ͨ��ʱ������ж��Ƿ���bound��
// ���ݹٷ��ĵ���The stamp that is set to zero until the image is bound.
// ������ʱ�����0����ô��˵�����PE�ļ���unbound��
_ila_rva = convert_rva_to_file_pointer(_ila_rva, p_section_header, number_of_sections);
if(_is_bound>0) {
    // ��bound���Ȳ���
} else {
    
    cout("û�а�\n");
    int _break_flag=0;
    _ui _up_value = 0;
    while(1) {
        // cout("������ħ���ˣ�");
         
        FUCK("_ila_rva 0x%x\n", _ila_rva);
        // ��Ϊ����һ������������Ҫһֱ��ͣ�ض���ֱ����ȡ������image_bse_sizeofȫ���ǿ�
        // unbound
        // ֱ�ӿ�ILT��import loookup table������
        // ����PE32��PE32+������ǰ��Ϊ32bit������Ϊ64bit
        // ͨ��image_bse_sizeof���ǿ���ȷ������pe32����pe32+
        _ui _hint_name_table_rva;
        _ui _ordinal;
        FUCK("_ila_rva 0x%x\n", _ila_rva);
        
        strm.seekg (_ila_rva+_up_value);
        memset(buffer,0,64);
        // PE32+ռ��64bit����8bytes
        strm.read(buffer, image_bse_sizeof);
        _up_value+=image_bse_sizeof;
        for(int i=0;i<image_bse_sizeof;i++) {
            _break_flag = 0;
            unsigned char _asd = 0;
            _asd = (unsigned char)buffer[i];
            if(_asd > 0) {break;}
            if(i+2>image_bse_sizeof) _break_flag = 1;
        }
        if(_break_flag>0) break;
        // Ordinal Number������ֶ�ֻ����Ordinal/Name��־λ���õ�ʱ��Ż�������
        // ���������Ҫ�Ȳ鿴���һ��bitλ����Ϊ���һ��bitλ������Ordinal/Name��־λ�Ƿ�����
        _ui _temp_fucking_value;
        if(image_bse_sizeof>4)
            _temp_fucking_value = (_ui)buffer[7];
        else
            _temp_fucking_value = (_ui)buffer[3];
        if(_temp_fucking_value>0) {
            // ����ordinal
            hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
            sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
            strcpy(hex_sting, _tmnp_string);
            sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
            strcat(hex_sting, _tmnp_string);
            FUCK("hex_sting: %s",hex_sting);
            free(hex_sting);
            _ordinal = (_ui)strtoul(hex_sting,NULL,16);
        } else {
            _hint_name_table_rva = _4_bytes_deal(buffer);
        
            cout("HINT/NAME table RVA��");
            printf("\n\t0x%x\n", _hint_name_table_rva);
            // ��RVAת����disk file pointer

            _hint_name_table_rva = convert_rva_to_file_pointer(_hint_name_table_rva, p_section_header, number_of_sections);
            
            // Ȼ�����_hint_name_table_rva����ȡHINT/NAME Table
            strm.seekg (_hint_name_table_rva);
            memset(buffer,0,64);
            // 2bytes��hint������ʱ����������hint��ɶ��
            strm.read(buffer, 2);
          // ���� _up_value+=2;
            _ui _hint = _2_bytes_deal(buffer);
            cout("HINT��");
            printf("0x%x\n", _hint);
            
            // Ȼ�������Ҫ����ĺ��������ƣ�ascii�ַ�������NULL��β�����Ծ�һֱ��ȡ��������
            char function_name[4086]={0};
            _read_ascii(_hint_name_table_rva+2, &strm, function_name);
            // _up_value=_up_value+strlen(function_name)+1;
            cout("��������");
            printf("\t%s\n", function_name);
        }
    }

}raw_offset+=20;
}
// raw_offset = _boss_up_value;


// �ٽ���һ��data directory  base reloc
// ��Ӧ.reloc   ֮ǰ��import table��Ӧ.idata
//return 0;
//stdout.close();
fclose(stdout);
cout("--------------------------base relocation table\n");
exit( 0);
// ����ṹ�������import table��࣬Ҳ�����޽ṹ��ֻ����û�н�����־����ͨ��size���ж��Ƿ����
// ������Ҫ��ȡreloca trable��rva��size���������ֱ��ʹ�����ǵ�data_directory_map��ȡ
 data_directory_map[_TEXT("base_relocation_table")].addr;
 data_directory_map[_TEXT("base_relocation_table")].size;

//  ͨ��RVA����file pointer
_ui _file_pointer_to_relocation_table = convert_rva_to_file_pointer(data_directory_map[_TEXT("base_relocation_table")].addr, p_section_header, number_of_sections);

// �������̫�˷�ʱ���ˣ��о�Ҳûɶ�ã���ע�͵�
//
_boss_up_value=_file_pointer_to_relocation_table;
while(1){
    _ui _temp_fuck_value = _file_pointer_to_relocation_table-_boss_up_value;
    if(_temp_fuck_value>= data_directory_map[_TEXT("base_relocation_table")].size) break;
    strm.seekg (_file_pointer_to_relocation_table);
    memset(buffer,0,64);
    // ��ȡpage rva
    strm.read(buffer, 4);
    time_stamp_umber_of_sections = _4_bytes_deal(buffer);
    cout("\npage RVA��");
    printf("\t0x%x\n", time_stamp_umber_of_sections);
    acout("\n");
    strm.seekg (_file_pointer_to_relocation_table+4);
    memset(buffer,0,64);
    // ��ȡblock size
    strm.read(buffer, 4);
    time_stamp_umber_of_sections = _4_bytes_deal(buffer);
    cout("size��");
    _ui __block_size = time_stamp_umber_of_sections;
    printf("\t0x%x\n++++++++++++++++++++++++++++++++++", time_stamp_umber_of_sections);
    acout("\n");
    _ui _up_value = 0;
    while((_up_value)<(__block_size-8)) {
        strm.seekg (_file_pointer_to_relocation_table+4+4+_up_value);
        memset(buffer,0,64);
        // ��ȡblock size
        strm.read(buffer, 2);
        unsigned short _fuck_you = _2_bytes_deal(buffer);
        // ��ȡ���4bit
        _ui _high_4_bit = (_ui)(_fuck_you >> 12);
        cout("base relocation ���ͣ�");
        printf("\t0x%x\n", _high_4_bit);
        _ui _offset_value = _fuck_you & 0xFFF;
        cout("ƫ������");
        printf("\t0x%x\n", _offset_value);
        _up_value+=2;
    }
    _file_pointer_to_relocation_table+=__block_size;
}
cout("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@����----����data directory----����@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");



return 0;


}

////???????????
//#include <Windows.h>
//#include <iostream>
//#include <io.h>
//#include <fcntl.h>
//#include <locale.h>
//#include <wincon.h>
//
//int wmain(int argc, wchar_t* argv[])
//{
//char* hex_sting= "82E1734B";
//signed int number_of_sections=(signed int)strtoul(hex_sting,NULL,16);
//printf("%d\n",number_of_sections);
//    return 0;
//}

/*
_ui _4_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[8+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    FUCK("hex_sting: %s",hex_sting);
    return (_ui)strtoul(hex_sting,NULL,16);
*/