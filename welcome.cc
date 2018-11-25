/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <iostream>
#include <stdio.h>
#include <fstream>

char* strChar(char *_in, int _pos, char _ch)
{
  _in[_pos]=_ch;
  return _in;
}


int main(int argc, char**argv)
{
  //Prints welcome message...
  char *a;


  //Prints arguments...
  if (argc > 1 && (int)argv[1]>0)
   {
     std::ifstream dic("simbols.dic", std::ifstream::binary);
     std::ifstream dic2("simbols.dic", std::ifstream::binary);

     
     int num = atoi(argv[1]);
     a = new char[num+1]();
     std::cout << "Arguments:"<<num<< std::endl ;

     for (int i = 0; i < num; i++)
     {
       a[i]='a';
     }
     a[num]='\0';

     std::cout << "Result:" << a << std::endl ;
     char c;

     while (dic.get(c))
     {
       //       while (dic.get
       for (int j = 0; j < num; j++)
       {
       	 std::cout << "Result"<<j<<"-"<<num<<":"<< strChar(a, j, c) << std::endl ;
       }
     }
     dic.seekg(0, dic.beg);


     delete [] a;
     dic.close();
     dic2.close();
   }
  
   return 0;
}
