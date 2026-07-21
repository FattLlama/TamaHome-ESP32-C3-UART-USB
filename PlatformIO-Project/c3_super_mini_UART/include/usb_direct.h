#ifndef USB_DIRECT_H
#define USB_DIRECT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Direct USB JTAG write, no interrupts, no driver.
int usb_write(uint8_t *buf, uint32_t len);

// Direct USB JTAG read, no interrupts, no driver.
int usb_read(uint8_t *buf, uint32_t len);

void usb_clear_buffers(void);

#ifdef __cplusplus
}
#endif

#endif // USB_DIRECT_H