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
  FILE* card = fopen("card.raw", "r");
  if ("card.raw" == NULL)
  {
    printf("Please make sure that card.raw exists");
    return 2;
  }

  // declare the empty 512-integer array
  unsigned int buffer[512];

  // scanf("%d", buffer);
  // Recrusively add 512 bytes into buffer
  fread(&buffer, 512, 1, card);

  // start of a new JPG
  // Yes

    // Open a new JPG
    // Write the JPG
    // Close and Loop agian

  // No

    //Go through the loop agian

  //Close any remaining files
}
