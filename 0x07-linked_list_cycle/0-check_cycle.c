#include "lists.h"
int check_cycle(listint_t *list)
{
	listint_t *pslow, *pfast;

	pslow = list;
	pfast = list;
	while (pslow && pfast && pfast->next)
	  {
	    pslow = pslow->next;
	    pfast = pfast->next->next;
	    if (pslow == pfast)
	      return (1);
	  }
return (0);
}
