#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int index_count=0,sort_count=0;
    float sum=0,temp_number=0;
    /*sorting the array*/
    for (index_count=0;index_count<setlength;index_count++)
    {
	for(sort_count=0;sort_count<setlength;sort_count++)
	{
	   if(numberset[index_count]>numberset[sort_count])
	    {
		temp_number = numberset[index_count];
		numberset[index_count]= numberset[sort_count];
		numberset[sort_count]=temp_number;
	    }
	}
	sum+=numberset[index_count];
     }
    /*average*/
    s.average=(sum/setlength);
    /*minimum*/
    s.min=numberset[0];
    /*maximum*/
    s.max=numberset[setlength-1];
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
