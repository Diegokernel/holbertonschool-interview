#include "slide_line.h"

/**
 * slide_line - slides a line either left or right
 * @line: input array
 * @size: size of array
 * @direction: direction to slide
 * Return: 0 on failure, 1 on success
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t sld_stp, slideidx;
	int curr = 0, i;

	if (!line || size <= 0)
		return (0);
	switch (direction)
	  {
	  case SLIDE_LEFT:
	    i = 1;
	    slideidx = 0;
	    sld_stp = 0;
	    break;
	  case SLIDE_RIGHT:
	    i = -1;
	    slideidx = size - 1;
	    sld_stp = slideidx;
	    break;
	  }
	
	while (sld_stp < size)
	  {
	    if (line[sld_stp] == 0)
		{
		  sld_stp += i;
		  continue;
		}
	    if (curr == line[sld_stp])
	      {
		line[slideidx] = last * 2;
		slideidx += i;
		curr = 0;
	      }
	    else if (curr != 0)
	      {
		line[slideidx] = last;
		slideidx += i;
		curr = line[sld_stp];
	      }
	    else
	      curr = line[sld_stp];
	    line[sld_stp] = 0;
	    sld_stp += i;
	  }
	if (curr != 0)
	  line[slideidx] = curr;
	return (1);
}
