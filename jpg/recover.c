#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

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
    printf("Please make sure that card.raw exists");
    return 2;
  }


  // declare the empty 512-integer array
  uint8_t buffer[512];

  // scanf("%hhu", buffer);
  // Recrusively add 512 bytes into buffer

    fread(buffer, BLOCK_SIZE, 1, card);
    printf("BYTE: %02x\n", buffer[0]);

  // start of a new JPG
  // Yes

    // Open a new JPG
    // Write the JPG
    // Close and Loop agian

  // No

    //Go through the loop agian

  //Close any remaining files
  fclose(card);
  return 0;
}
