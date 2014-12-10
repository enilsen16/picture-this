#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // ensure proper usage
  if (argc != 1)
  {
    printf("Please remember that recover.c is for card.raw specifically\n");
    return 1;
  }

  // open card.raw
  FILE* card = fopen("./jpg/card.raw", "r");
  if (card == NULL)
  {
    printf("Please make sure that card.raw exists\n");
    return 2;
  }

  int count = 0;
  // declare the empty 512-integer array
  uint8_t buffer[512];
  FILE* outptr = NULL;


  while (fread(buffer, 512, 1, card))
  {
    // start of a new JPG
    // Yes
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe1 || buffer[3] == 0xe0))
    {
      // close file if it hasnt already
      if (outptr != NULL)fclose(outptr);

      // Open a new JPG
      char name[8];
      sprintf(name, "%03d.jpg", count);
      outptr = fopen(name, "w");
      count++;
    }
    // Write the JPG
    if (outptr != NULL)
    {
      fwrite(buffer, 512, 1, outptr);
    }
  }

  if (outptr != NULL) fclose(outptr);

  //Close any remaining files
  fclose(card);
  return 0;
}
