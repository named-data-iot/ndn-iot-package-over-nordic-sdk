#include "stdio.h"
#include "string.h"
#include "alarm-adaptation/system.h"
#include "flash-storage/flash.h"

static uint32_t address = 0;
static uint32_t data = 12345;
static char string[] = "ndn_flash_storage_string";

int main()
{
  // Initialize the Platform
  printf("Hello in NDN Lite Example: Flash Storage\n");
  ndn_platform_init();

  // Do Flash Operation Only If Ready
  if (ndn_flash_status() == NDN_PLAT_FLASH_READY)
  {
    // Check If Existing Storage Matches
    uint8_t buffer_data[sizeof(data)];
    uint8_t buffer_string[strlen(string)];
    ndn_flash_read(address, buffer_data, sizeof(data));
    ndn_flash_read(address + sizeof(data), buffer_string, strlen(string));

    int r1 = memcmp(buffer_data, (uint8_t*)&data, sizeof(data));
    int r2 = memcmp(buffer_string, (uint8_t*)string, strlen(string));

    if (r1 == 0 && r2 == 0)
    {
      // If Success, Erase that Page
      uint32_t convert = 0;
      memcpy((uint8_t*)&convert, buffer_data, sizeof(data));

      printf("Flash Storage Success: %ld\n", convert);
      printf("Flash Storage Success: %s\n", (char*)buffer_string);
      ndn_flash_erase(address);
    }
    else
    {
      // Check Usable Flash Space and Prepare to Write
      printf("Usable Flash Size: %d bytes\n", (int)ndn_flash_get());
      printf("Write Flash with Data and String\n");

      // Erase Page and Write
      ndn_flash_erase(address);
      ndn_flash_write(address, (uint8_t*)&data, sizeof(data));
      ndn_flash_write(address + sizeof(data), (uint8_t*)string, strlen(string));
      printf("Write completion. Please Press RESET Button to Check Storage Result\n");
    }
  }

  while(1) {}
}
