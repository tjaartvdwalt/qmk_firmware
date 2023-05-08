# A Programmers Dvorak Planck Layout

On 
```bash
# For avr-gcc > 11 you need to pass the flags
make planck/rev5:tjaartvdwalt AVR_CFLAGS="-Wno-array-bounds"

sudo dfu-programmer atmega32u4 erase --force
sudo dfu-programmer  atmega32u4 flash planck_rev5_tjaartvdwalt.hex
sudo dfu-programmer atmega32u4 reset

```
