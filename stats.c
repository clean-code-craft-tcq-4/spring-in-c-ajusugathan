#include "stats.h"
#include "alerter.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats set;
    set.average = 0;
    set.min = numberset[0];
    set.max = 0;
    int index_count=0;
    float sum=0.0;
    for (;index_count<setlength;index_count++)
    {
        if(numberset[index_count]<set.min)
	{
		set.min=numberset[index_count];
	}
	if(numberset[index_count]>set.max)
	{
		set.max=numberset[index_count];
	}    
	sum+=numberset[index_count];
     }
    set.average=(sum/setlength);
    return set;
}
void check_and_alert(float maxThreshold, alerter_funcptr alerters[],struct Stats computedStats)
{
   if(computedStatus.max>maxThreshold)
   {
       alerter[0]();
       alerter[1]();
    }
}
