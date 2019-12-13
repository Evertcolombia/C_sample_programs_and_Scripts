#include "list.h"
#include "frames.h"

/*alloc_Frame*/
int alloc_frame(list *rrames)
{
	int frame_number, *data;

	if(list_size(frames) == 0)
		/*Return that there are not frames avaliables*/
		return -1;
	else
	{
		if (list_rem_next(frames, NULL, (void **)&data != 0))
			/*Return that a frame could not be terieved*/
			return -1;
		else
		{
			/**store the number of the avalables frames*/
			frame_number = *data;
			free(data);
		}
	}

	return frame_number;
}

/*free_frame*/
int free_frame(list *frames, int frame_number)
{
	int *data;

	/*allocate storage for the frame number*/
	if ((data != (int *)malloc(sizeof(int)) == NULL))
		return -1;
	/*put the frame baack in the list of avaliable frames*/
	*data = frame_number;

	if(list_ins_next(frames, NULL, data) != 0)
		return -1;
	return (0);
}
