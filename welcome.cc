#include <iostream>
#include <stdio.h>
#include <fstream>

char* strChar(char*_in, int _pos, char _ch)
{
  _in[_pos]=_ch;
  return _in;
}


void print_this(int*mas, int mas_length)
{
  /*
  std::cout << "Result: ";
  for(int i=0; i<=mas_length; i++)
    std::cout<<mas[i]<<":";
  std::cout<< std::endl;
  */
  std::ifstream dic("simbols.dic", std::ifstream::binary);

  std::cout << "Word: ";
  for(int i=0; i<=mas_length; i++)
  {
     char f_c;
     if(mas[i]>=0)
     {
       dic.seekg(mas[i], dic.beg);
       dic.get(f_c);
       std::cout<<f_c;
     }
  }
  std::cout<<std::endl;
  

  return;
}

void do_this(int word_length, int dic_length, int*a, int cur)
{
  //  std::cout<<"cur: "<<cur<<std::endl;

    if(cur<0)
      {
	//	std::cout<<"exit"<<std::endl;
	return;
      }

    
    a[cur]++;
    if(a[cur]>=dic_length)
    {
      // std::cout<<"up"<<std::endl;
      for(int i=cur; i<=word_length;i++)
      {
	a[i]=0;
      }
      do_this(word_length, dic_length, a, cur-1);
     
    }
    else
    {
      print_this(a, word_length);
      do_this(word_length, dic_length, a, word_length);
    }
      
  return;
}


int main(int argc, char**argv)
{
  int* pos_mas;

  //Prints welcome message...
  //Prints arguments...
  if (argc > 2 && (int)argv[1]>0 && (int)argv[2]>=0)
   {
     
     int num = atoi(argv[1]);
     int full_check= atoi(argv[2]);
     pos_mas = new int[num];
     std::cout << "Length word:" << num << std::endl ;

 

     for(int i=0; i<num; i++)
       if(full_check==0)
	 pos_mas[i] = 0;
       else
	 pos_mas[i] = -1;

       

     print_this(pos_mas, num-1);
     
     std::ifstream dic("simbols.dic", std::ifstream::binary);
     dic.seekg(0, dic.beg);
     dic.seekg(0, dic.end);
     int length=dic.tellg();
     dic.seekg(0, dic.beg);

     std::cout << "Length dic:" << length << std::endl ;
     
     if(full_check == 0)
       do_this(num-1,length, pos_mas, 0);
     else
       do_this(num-1,length, pos_mas, num-1);


   }
    delete[] pos_mas;
   return 0;
}


/*
{

    std::ifstream dic(dic_name, std::ifstream::binary);

    int *aa = new int[razr]();
    char c;
    char f_c;
    dic.seekg(0, dic.beg);
    dic.get(f_c);
    dic.seekg(0, dic.end);
    int length=dic.tellg();
    dic.seekg(0, dic.beg);

    std::cout << "Start: "<<cur_razr<<"/"<<razr<<" " << a << std::endl ;
    std::cout << "Length dic:" << length << std::endl ;


    //if (init==true)
    //{
      	  //init first simbol
	  for(int l = razr; l>=cur_razr; l--)
	  {
	    strChar(a, l, f_c);
	    aa[l] = 0;
	  }
	  std::cout << "init: "<<a << std::endl ;
	  //}



    for(int j = razr; j >= 0; j--)
    {

	for(int i = razr; i>=j; i--)
	{
	  for(; aa[i]<length; aa[i]++)
	  {
	    dic.seekg(aa[i], dic.beg);
	    dic.get(c);
 	    std::cout << "Result"<<j<<"-"<<i<<"-"<<aa[i]<<":"<< strChar(a, i, c) << std::endl ;
	  }
	  strChar(a, i, f_c);
	  if(i!=0)
	  {
	    aa[i-1]++;
            for(int ii=razr; ii>i; ii--)
	    {
	      aa[ii]=0;
	    }
	  }   
	    
	  if(i!=0)
          {

	    do_this(i-1, razr, dic_name, a, false);
          }
	}
	
    }
   dic.close();

   return a;
}

 */
