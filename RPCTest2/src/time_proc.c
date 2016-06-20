/* time_proc.c: implementation of the remote procedure "printime" */

#include <stdio.h>
#include <rpc/rpc.h>           /* always needed */
#include "time.h"                  /* time.h will be generated by rpcgen */
#include <time.h>

/* Remote version of "printime" */
char ** printime_1_svc(char **msg,struct svc_req *req)
{
   static char * result; /* must be static! */
   static char tmp_char[100];
   time_t rawtime;

   FILE *f;

   f = fopen("/tmp/rpc_result", "a+");
   if (f == (FILE *)NULL) {
     strcpy(tmp_char,"Error");
     result = tmp_char;;
     return (&result);
    }

   fprintf(f, "%s", *msg);                      //used for debugging
   fclose(f);
   time(&rawtime);
   sprintf(tmp_char,"Current time is :%s",ctime(&rawtime));
   result =tmp_char;
   return (&result);
}
