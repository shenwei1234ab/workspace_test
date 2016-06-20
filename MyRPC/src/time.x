struct ReqLogin     
{
    int  id;    
};

struct ResLogin
{
	int result;
};



program TIMEPROG {  
   version PRINTIMEVERS {  
     ResLogin PRINTIME(ReqLogin) = 1; /* 过程号 :返回值（函数名 参数类型） */  
   } = 1; /* 版本号 */  
} = 0x20000001; /* 程序号 */ 