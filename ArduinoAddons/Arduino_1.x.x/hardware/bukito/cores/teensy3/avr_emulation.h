/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows 
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _avr_emulation_h_
#define _avr_emulation_h_

#include "mk20dx128.h"
#include "core_pins.h"
#include "pins_arduino.h"

#ifdef __cplusplus

#define GPIO_BITBAND_ADDR(reg, bit) (((uint32_t)&(reg) - 0x40000000) * 32 + (bit) * 4 + 0x42000000)
#define GPIO_BITBAND(reg, bit) (*(uint32_t *)GPIO_BITBAND_ADDR((reg), (bit)))
#define CONFIG_PULLUP (PORT_PCR_MUX(1) | PORT_PCR_PE | PORT_PCR_PS)
#define CONFIG_NOPULLUP (PORT_PCR_MUX(1))

class PORTDemulation
{
public:
	inline PORTDemulation & operator = (int val) __attribute__((always_inline)) {
		digitalWriteFast(0, (val & (1<<0)));
		if (!(CORE_PIN0_DDRREG & CORE_PIN0_BIT)) 
			CORE_PIN0_CONFIG = ((val & (1<<0)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(1, (val & (1<<1)));
		if (!(CORE_PIN1_DDRREG & CORE_PIN1_BIT)) 
			CORE_PIN1_CONFIG = ((val & (1<<1)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(2, (val & (1<<2)));
		if (!(CORE_PIN2_DDRREG & CORE_PIN2_BIT)) 
			CORE_PIN2_CONFIG = ((val & (1<<2)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(3, (val & (1<<3)));
		if (!(CORE_PIN3_DDRREG & CORE_PIN3_BIT)) 
			CORE_PIN3_CONFIG = ((val & (1<<3)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(4, (val & (1<<4)));
		if (!(CORE_PIN4_DDRREG & CORE_PIN4_BIT)) 
			CORE_PIN4_CONFIG = ((val & (1<<4)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(5, (val & (1<<5)));
		if (!(CORE_PIN5_DDRREG & CORE_PIN5_BIT)) 
			CORE_PIN5_CONFIG = ((val & (1<<5)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(6, (val & (1<<6)));
		if (!(CORE_PIN6_DDRREG & CORE_PIN6_BIT)) 
			CORE_PIN6_CONFIG = ((val & (1<<6)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(7, (val & (1<<7)));
		if (!(CORE_PIN7_DDRREG & CORE_PIN7_BIT)) 
			CORE_PIN7_CONFIG = ((val & (1<<7)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		return *this;
	}
	inline PORTDemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) {
			digitalWriteFast(0, HIGH);
			if (!(CORE_PIN0_DDRREG & CORE_PIN0_BIT)) CORE_PIN0_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<1)) {
			digitalWriteFast(1, HIGH);
			if (!(CORE_PIN1_DDRREG & CORE_PIN1_BIT)) CORE_PIN1_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<2)) {
			digitalWriteFast(2, HIGH);
			if (!(CORE_PIN2_DDRREG & CORE_PIN2_BIT)) CORE_PIN2_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<3)) {
			digitalWriteFast(3, HIGH);
			if (!(CORE_PIN3_DDRREG & CORE_PIN3_BIT)) CORE_PIN3_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<4)) {
			digitalWriteFast(4, HIGH);
			if (!(CORE_PIN4_DDRREG & CORE_PIN4_BIT)) CORE_PIN4_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<5)) {
			digitalWriteFast(5, HIGH);
			if (!(CORE_PIN5_DDRREG & CORE_PIN5_BIT)) CORE_PIN5_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<6)) {
			digitalWriteFast(6, HIGH);
			if (!(CORE_PIN6_DDRREG & CORE_PIN6_BIT)) CORE_PIN6_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<7)) {
			digitalWriteFast(7, HIGH);
			if (!(CORE_PIN7_DDRREG & CORE_PIN7_BIT)) CORE_PIN7_CONFIG = CONFIG_PULLUP;
		}
		return *this;
	}
	inline PORTDemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) {
			digitalWriteFast(0, LOW);
			if (!(CORE_PIN0_DDRREG & CORE_PIN0_BIT)) CORE_PIN0_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<1))) {
			digitalWriteFast(1, LOW);
			if (!(CORE_PIN1_DDRREG & CORE_PIN1_BIT)) CORE_PIN1_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<2))) {
			digitalWriteFast(2, LOW);
			if (!(CORE_PIN2_DDRREG & CORE_PIN2_BIT)) CORE_PIN2_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<3))) {
			digitalWriteFast(3, LOW);
			if (!(CORE_PIN3_DDRREG & CORE_PIN3_BIT)) CORE_PIN3_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<4))) {
			digitalWriteFast(4, LOW);
			if (!(CORE_PIN4_DDRREG & CORE_PIN4_BIT)) CORE_PIN4_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<5))) {
			digitalWriteFast(5, LOW);
			if (!(CORE_PIN5_DDRREG & CORE_PIN5_BIT)) CORE_PIN5_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<6))) {
			digitalWriteFast(6, LOW);
			if (!(CORE_PIN6_DDRREG & CORE_PIN6_BIT)) CORE_PIN6_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<7))) {
			digitalWriteFast(7, LOW);
			if (!(CORE_PIN7_DDRREG & CORE_PIN7_BIT)) CORE_PIN7_CONFIG = CONFIG_NOPULLUP;
		}
		return *this;
	}
};
extern PORTDemulation PORTD;

class PINDemulation
{
public:
	inline int operator & (int val) const __attribute__((always_inline)) {
		int ret = 0;
		if ((val & (1<<0)) && digitalReadFast(0)) ret |= (1<<0);
		if ((val & (1<<1)) && digitalReadFast(1)) ret |= (1<<1);
		if ((val & (1<<2)) && digitalReadFast(2)) ret |= (1<<2);
		if ((val & (1<<3)) && digitalReadFast(3)) ret |= (1<<3);
		if ((val & (1<<4)) && digitalReadFast(4)) ret |= (1<<4);
		if ((val & (1<<5)) && digitalReadFast(5)) ret |= (1<<5);
		if ((val & (1<<6)) && digitalReadFast(6)) ret |= (1<<6);
		if ((val & (1<<7)) && digitalReadFast(7)) ret |= (1<<7);
		return ret;
	}
	operator int () const __attribute__((always_inline)) {
		int ret = 0;
		if (digitalReadFast(0)) ret |= (1<<0);
		if (digitalReadFast(1)) ret |= (1<<1);
		if (digitalReadFast(2)) ret |= (1<<2);
		if (digitalReadFast(3)) ret |= (1<<3);
		if (digitalReadFast(4)) ret |= (1<<4);
		if (digitalReadFast(5)) ret |= (1<<5);
		if (digitalReadFast(6)) ret |= (1<<6);
		if (digitalReadFast(7)) ret |= (1<<7);
		return ret;
	}
};
extern PINDemulation PIND;

class DDRDemulation
{
public:
	inline DDRDemulation & operator = (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0(); else clr0();
		if (val & (1<<1)) set1(); else clr1();
		if (val & (1<<2)) set2(); else clr2();
		if (val & (1<<3)) set3(); else clr3();
		if (val & (1<<4)) set4(); else clr4();
		if (val & (1<<5)) set5(); else clr5();
		if (val & (1<<6)) set6(); else clr6();
		if (val & (1<<7)) set7(); else clr7();
		return *this;
	}
	inline DDRDemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0();
		if (val & (1<<1)) set1();
		if (val & (1<<2)) set2();
		if (val & (1<<3)) set3();
		if (val & (1<<4)) set4();
		if (val & (1<<5)) set5();
		if (val & (1<<6)) set6();
		if (val & (1<<7)) set7();
		return *this;
	}
	inline DDRDemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) clr0();
		if (!(val & (1<<1))) clr1();
		if (!(val & (1<<2))) clr2();
		if (!(val & (1<<3))) clr3();
		if (!(val & (1<<4))) clr4();
		if (!(val & (1<<5))) clr5();
		if (!(val & (1<<6))) clr6();
		if (!(val & (1<<7))) clr7();
		return *this;
	}
private:
	inline void set0() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN0_DDRREG, CORE_PIN0_BIT) = 1;
		CORE_PIN0_CONFIG = CONFIG_PULLUP;
	}
	inline void set1() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN1_DDRREG, CORE_PIN1_BIT) = 1;
		CORE_PIN1_CONFIG = CONFIG_PULLUP;
	}
	inline void set2() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN2_DDRREG, CORE_PIN2_BIT) = 1;
		CORE_PIN2_CONFIG = CONFIG_PULLUP;
	}
	inline void set3() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN3_DDRREG, CORE_PIN3_BIT) = 1;
		CORE_PIN3_CONFIG = CONFIG_PULLUP;
	}
	inline void set4() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN4_DDRREG, CORE_PIN4_BIT) = 1;
		CORE_PIN4_CONFIG = CONFIG_PULLUP;
	}
	inline void set5() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN5_DDRREG, CORE_PIN5_BIT) = 1;
		CORE_PIN5_CONFIG = CONFIG_PULLUP;
	}
	inline void set6() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN6_DDRREG, CORE_PIN6_BIT) = 1;
		CORE_PIN6_CONFIG = CONFIG_PULLUP;
	}
	inline void set7() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN7_DDRREG, CORE_PIN7_BIT) = 1;
		CORE_PIN7_CONFIG = CONFIG_PULLUP;
	}
	inline void clr0() __attribute__((always_inline)) {
		CORE_PIN0_CONFIG = ((CORE_PIN0_PORTREG & CORE_PIN0_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN0_DDRREG, CORE_PIN0_BIT) = 0;
	}
	inline void clr1() __attribute__((always_inline)) {
		CORE_PIN1_CONFIG = ((CORE_PIN1_PORTREG & CORE_PIN1_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN1_DDRREG, CORE_PIN1_BIT) = 0;
	}
	inline void clr2() __attribute__((always_inline)) {
		CORE_PIN2_CONFIG = ((CORE_PIN2_PORTREG & CORE_PIN2_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN2_DDRREG, CORE_PIN2_BIT) = 0;
	}
	inline void clr3() __attribute__((always_inline)) {
		CORE_PIN3_CONFIG = ((CORE_PIN3_PORTREG & CORE_PIN3_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN3_DDRREG, CORE_PIN3_BIT) = 0;
	}
	inline void clr4() __attribute__((always_inline)) {
		CORE_PIN4_CONFIG = ((CORE_PIN4_PORTREG & CORE_PIN4_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN4_DDRREG, CORE_PIN4_BIT) = 0;
	}
	inline void clr5() __attribute__((always_inline)) {
		CORE_PIN5_CONFIG = ((CORE_PIN5_PORTREG & CORE_PIN5_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN5_DDRREG, CORE_PIN5_BIT) = 0;
	}
	inline void clr6() __attribute__((always_inline)) {
		CORE_PIN6_CONFIG = ((CORE_PIN6_PORTREG & CORE_PIN6_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN6_DDRREG, CORE_PIN6_BIT) = 0;
	}
	inline void clr7() __attribute__((always_inline)) {
		CORE_PIN7_CONFIG = ((CORE_PIN7_PORTREG & CORE_PIN7_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN7_DDRREG, CORE_PIN7_BIT) = 0;
	}
};

extern DDRDemulation DDRD;






class PORTBemulation
{
public:
	inline PORTBemulation & operator = (int val) __attribute__((always_inline)) {
		digitalWriteFast(8, (val & (1<<0)));
		if (!(CORE_PIN8_DDRREG & CORE_PIN8_BIT)) 
			CORE_PIN8_CONFIG = ((val & (1<<0)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(9, (val & (1<<1)));
		if (!(CORE_PIN9_DDRREG & CORE_PIN9_BIT)) 
			CORE_PIN9_CONFIG = ((val & (1<<1)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(10, (val & (1<<2)));
		if (!(CORE_PIN10_DDRREG & CORE_PIN10_BIT)) 
			CORE_PIN10_CONFIG = ((val & (1<<2)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(11, (val & (1<<3)));
		if (!(CORE_PIN11_DDRREG & CORE_PIN11_BIT)) 
			CORE_PIN11_CONFIG = ((val & (1<<3)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(12, (val & (1<<4)));
		if (!(CORE_PIN12_DDRREG & CORE_PIN12_BIT)) 
			CORE_PIN12_CONFIG = ((val & (1<<4)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(13, (val & (1<<5)));
		if (!(CORE_PIN13_DDRREG & CORE_PIN13_BIT)) 
			CORE_PIN13_CONFIG = ((val & (1<<5)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		return *this;
	}
	inline PORTBemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) {
			digitalWriteFast(8, HIGH);
			if (!(CORE_PIN7_DDRREG & CORE_PIN7_BIT)) CORE_PIN8_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<1)) {
			digitalWriteFast(9, HIGH);
			if (!(CORE_PIN7_DDRREG & CORE_PIN7_BIT)) CORE_PIN9_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<2)) {
			digitalWriteFast(10, HIGH);
			if (!(CORE_PIN10_DDRREG & CORE_PIN10_BIT)) CORE_PIN10_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<3)) {
			digitalWriteFast(11, HIGH);
			if (!(CORE_PIN11_DDRREG & CORE_PIN11_BIT)) CORE_PIN11_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<4)) {
			digitalWriteFast(12, HIGH);
			if (!(CORE_PIN12_DDRREG & CORE_PIN12_BIT)) CORE_PIN12_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<5)) {
			digitalWriteFast(13, HIGH);
			if (!(CORE_PIN13_DDRREG & CORE_PIN13_BIT)) CORE_PIN13_CONFIG = CONFIG_PULLUP;
		}
		return *this;
	}
	inline PORTBemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) {
			digitalWriteFast(8, LOW);
			if (!(CORE_PIN8_DDRREG & CORE_PIN8_BIT)) CORE_PIN8_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<1))) {
			digitalWriteFast(9, LOW);
			if (!(CORE_PIN9_DDRREG & CORE_PIN9_BIT)) CORE_PIN9_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<2))) {
			digitalWriteFast(10, LOW);
			if (!(CORE_PIN10_DDRREG & CORE_PIN10_BIT)) CORE_PIN10_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<3))) {
			digitalWriteFast(11, LOW);
			if (!(CORE_PIN11_DDRREG & CORE_PIN11_BIT)) CORE_PIN11_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<4))) {
			digitalWriteFast(12, LOW);
			if (!(CORE_PIN12_DDRREG & CORE_PIN12_BIT)) CORE_PIN12_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<5))) {
			digitalWriteFast(13, LOW);
			if (!(CORE_PIN13_DDRREG & CORE_PIN13_BIT)) CORE_PIN13_CONFIG = CONFIG_NOPULLUP;
		}
		return *this;
	}
};
extern PORTBemulation PORTB;

class PINBemulation
{
public:
	inline int operator & (int val) const __attribute__((always_inline)) {
		int ret = 0;
		if ((val & (1<<0)) && digitalReadFast(8)) ret |= (1<<0);
		if ((val & (1<<1)) && digitalReadFast(9)) ret |= (1<<1);
		if ((val & (1<<2)) && digitalReadFast(10)) ret |= (1<<2);
		if ((val & (1<<3)) && digitalReadFast(11)) ret |= (1<<3);
		if ((val & (1<<4)) && digitalReadFast(12)) ret |= (1<<4);
		if ((val & (1<<5)) && digitalReadFast(13)) ret |= (1<<5);
		return ret;
	}
	operator int () const __attribute__((always_inline)) {
		int ret = 0;
		if (digitalReadFast(8)) ret |= (1<<0);
		if (digitalReadFast(9)) ret |= (1<<1);
		if (digitalReadFast(10)) ret |= (1<<2);
		if (digitalReadFast(11)) ret |= (1<<3);
		if (digitalReadFast(12)) ret |= (1<<4);
		if (digitalReadFast(13)) ret |= (1<<5);
		return ret;
	}
};
extern PINBemulation PINB;

class DDRBemulation
{
public:
	inline DDRBemulation & operator = (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0(); else clr0();
		if (val & (1<<1)) set1(); else clr1();
		if (val & (1<<2)) set2(); else clr2();
		if (val & (1<<3)) set3(); else clr3();
		if (val & (1<<4)) set4(); else clr4();
		if (val & (1<<5)) set5(); else clr5();
		return *this;
	}
	inline DDRBemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0();
		if (val & (1<<1)) set1();
		if (val & (1<<2)) set2();
		if (val & (1<<3)) set3();
		if (val & (1<<4)) set4();
		if (val & (1<<5)) set5();
		return *this;
	}
	inline DDRBemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) clr0();
		if (!(val & (1<<1))) clr1();
		if (!(val & (1<<2))) clr2();
		if (!(val & (1<<3))) clr3();
		if (!(val & (1<<4))) clr4();
		if (!(val & (1<<5))) clr5();
		return *this;
	}
private:
	inline void set0() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN8_DDRREG, CORE_PIN8_BIT) = 1;
		CORE_PIN8_CONFIG = CONFIG_PULLUP;
	}
	inline void set1() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN9_DDRREG, CORE_PIN9_BIT) = 1;
		CORE_PIN9_CONFIG = CONFIG_PULLUP;
	}
	inline void set2() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN10_DDRREG, CORE_PIN10_BIT) = 1;
		CORE_PIN10_CONFIG = CONFIG_PULLUP;
	}
	inline void set3() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN11_DDRREG, CORE_PIN11_BIT) = 1;
		CORE_PIN11_CONFIG = CONFIG_PULLUP;
	}
	inline void set4() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN12_DDRREG, CORE_PIN12_BIT) = 1;
		CORE_PIN12_CONFIG = CONFIG_PULLUP;
	}
	inline void set5() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN13_DDRREG, CORE_PIN13_BIT) = 1;
		CORE_PIN13_CONFIG = CONFIG_PULLUP;
	}
	inline void clr0() __attribute__((always_inline)) {
		CORE_PIN8_CONFIG = ((CORE_PIN8_PORTREG & CORE_PIN8_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN8_DDRREG, CORE_PIN8_BIT) = 0;
	}
	inline void clr1() __attribute__((always_inline)) {
		CORE_PIN9_CONFIG = ((CORE_PIN9_PORTREG & CORE_PIN9_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN9_DDRREG, CORE_PIN9_BIT) = 0;
	}
	inline void clr2() __attribute__((always_inline)) {
		CORE_PIN10_CONFIG = ((CORE_PIN10_PORTREG & CORE_PIN10_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN10_DDRREG, CORE_PIN10_BIT) = 0;
	}
	inline void clr3() __attribute__((always_inline)) {
		CORE_PIN11_CONFIG = ((CORE_PIN11_PORTREG & CORE_PIN11_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN11_DDRREG, CORE_PIN11_BIT) = 0;
	}
	inline void clr4() __attribute__((always_inline)) {
		CORE_PIN12_CONFIG = ((CORE_PIN12_PORTREG & CORE_PIN12_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN12_DDRREG, CORE_PIN12_BIT) = 0;
	}
	inline void clr5() __attribute__((always_inline)) {
		CORE_PIN13_CONFIG = ((CORE_PIN13_PORTREG & CORE_PIN13_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN13_DDRREG, CORE_PIN13_BIT) = 0;
	}
};

extern DDRBemulation DDRB;






class PORTCemulation
{
public:
	inline PORTCemulation & operator = (int val) __attribute__((always_inline)) {
		digitalWriteFast(14, (val & (1<<0)));
		if (!(CORE_PIN14_DDRREG & CORE_PIN14_BIT)) 
			CORE_PIN14_CONFIG = ((val & (1<<0)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(15, (val & (1<<1)));
		if (!(CORE_PIN15_DDRREG & CORE_PIN15_BIT)) 
			CORE_PIN15_CONFIG = ((val & (1<<1)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(16, (val & (1<<2)));
		if (!(CORE_PIN16_DDRREG & CORE_PIN16_BIT)) 
			CORE_PIN16_CONFIG = ((val & (1<<2)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(17, (val & (1<<3)));
		if (!(CORE_PIN17_DDRREG & CORE_PIN17_BIT)) 
			CORE_PIN17_CONFIG = ((val & (1<<3)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(18, (val & (1<<4)));
		if (!(CORE_PIN18_DDRREG & CORE_PIN18_BIT)) 
			CORE_PIN18_CONFIG = ((val & (1<<4)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		digitalWriteFast(19, (val & (1<<5)));
		if (!(CORE_PIN19_DDRREG & CORE_PIN19_BIT)) 
			CORE_PIN19_CONFIG = ((val & (1<<5)) ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		return *this;
	}
	inline PORTCemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) {
			digitalWriteFast(14, HIGH);
			if (!(CORE_PIN14_DDRREG & CORE_PIN14_BIT)) CORE_PIN14_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<1)) {
			digitalWriteFast(15, HIGH);
			if (!(CORE_PIN15_DDRREG & CORE_PIN15_BIT)) CORE_PIN15_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<2)) {
			digitalWriteFast(16, HIGH);
			if (!(CORE_PIN16_DDRREG & CORE_PIN16_BIT)) CORE_PIN16_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<3)) {
			digitalWriteFast(17, HIGH);
			if (!(CORE_PIN17_DDRREG & CORE_PIN17_BIT)) CORE_PIN17_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<4)) {
			digitalWriteFast(18, HIGH);
			if (!(CORE_PIN18_DDRREG & CORE_PIN18_BIT)) CORE_PIN18_CONFIG = CONFIG_PULLUP;
		}
		if (val & (1<<5)) {
			digitalWriteFast(19, HIGH);
			if (!(CORE_PIN19_DDRREG & CORE_PIN19_BIT)) CORE_PIN19_CONFIG = CONFIG_PULLUP;
		}
		return *this;
	}
	inline PORTCemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) {
			digitalWriteFast(14, LOW);
			if (!(CORE_PIN14_DDRREG & CORE_PIN14_BIT)) CORE_PIN14_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<1))) {
			digitalWriteFast(15, LOW);
			if (!(CORE_PIN15_DDRREG & CORE_PIN15_BIT)) CORE_PIN15_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<2))) {
			digitalWriteFast(16, LOW);
			if (!(CORE_PIN16_DDRREG & CORE_PIN16_BIT)) CORE_PIN16_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<3))) {
			digitalWriteFast(17, LOW);
			if (!(CORE_PIN17_DDRREG & CORE_PIN17_BIT)) CORE_PIN17_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<4))) {
			digitalWriteFast(18, LOW);
			if (!(CORE_PIN18_DDRREG & CORE_PIN18_BIT)) CORE_PIN18_CONFIG = CONFIG_NOPULLUP;
		}
		if (!(val & (1<<5))) {
			digitalWriteFast(19, LOW);
			if (!(CORE_PIN19_DDRREG & CORE_PIN19_BIT)) CORE_PIN19_CONFIG = CONFIG_NOPULLUP;
		}
		return *this;
	}
};
extern PORTCemulation PORTC;

class PINCemulation
{
public:
	inline int operator & (int val) const __attribute__((always_inline)) {
		int ret = 0;
		if ((val & (1<<0)) && digitalReadFast(8)) ret |= (1<<0);
		if ((val & (1<<1)) && digitalReadFast(9)) ret |= (1<<1);
		if ((val & (1<<2)) && digitalReadFast(10)) ret |= (1<<2);
		if ((val & (1<<3)) && digitalReadFast(11)) ret |= (1<<3);
		if ((val & (1<<4)) && digitalReadFast(12)) ret |= (1<<4);
		if ((val & (1<<5)) && digitalReadFast(13)) ret |= (1<<5);
		return ret;
	}
	operator int () const __attribute__((always_inline)) {
		int ret = 0;
		if (digitalReadFast(8)) ret |= (1<<0);
		if (digitalReadFast(9)) ret |= (1<<1);
		if (digitalReadFast(10)) ret |= (1<<2);
		if (digitalReadFast(11)) ret |= (1<<3);
		if (digitalReadFast(12)) ret |= (1<<4);
		if (digitalReadFast(13)) ret |= (1<<5);
		return ret;
	}
};
extern PINCemulation PINC;

class DDRCemulation
{
public:
	inline DDRCemulation & operator = (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0(); else clr0();
		if (val & (1<<1)) set1(); else clr1();
		if (val & (1<<2)) set2(); else clr2();
		if (val & (1<<3)) set3(); else clr3();
		if (val & (1<<4)) set4(); else clr4();
		if (val & (1<<5)) set5(); else clr5();
		return *this;
	}
	inline DDRCemulation & operator |= (int val) __attribute__((always_inline)) {
		if (val & (1<<0)) set0();
		if (val & (1<<1)) set1();
		if (val & (1<<2)) set2();
		if (val & (1<<3)) set3();
		if (val & (1<<4)) set4();
		if (val & (1<<5)) set5();
		return *this;
	}
	inline DDRCemulation & operator &= (int val) __attribute__((always_inline)) {
		if (!(val & (1<<0))) clr0();
		if (!(val & (1<<1))) clr1();
		if (!(val & (1<<2))) clr2();
		if (!(val & (1<<3))) clr3();
		if (!(val & (1<<4))) clr4();
		if (!(val & (1<<5))) clr5();
		return *this;
	}
private:
	inline void set0() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN14_DDRREG, CORE_PIN14_BIT) = 1;
		CORE_PIN14_CONFIG = CONFIG_PULLUP;
	}
	inline void set1() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN15_DDRREG, CORE_PIN15_BIT) = 1;
		CORE_PIN15_CONFIG = CONFIG_PULLUP;
	}
	inline void set2() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN16_DDRREG, CORE_PIN16_BIT) = 1;
		CORE_PIN16_CONFIG = CONFIG_PULLUP;
	}
	inline void set3() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN17_DDRREG, CORE_PIN17_BIT) = 1;
		CORE_PIN17_CONFIG = CONFIG_PULLUP;
	}
	inline void set4() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN18_DDRREG, CORE_PIN18_BIT) = 1;
		CORE_PIN18_CONFIG = CONFIG_PULLUP;
	}
	inline void set5() __attribute__((always_inline)) {
		GPIO_BITBAND(CORE_PIN19_DDRREG, CORE_PIN19_BIT) = 1;
		CORE_PIN19_CONFIG = CONFIG_PULLUP;
	}
	inline void clr0() __attribute__((always_inline)) {
		CORE_PIN14_CONFIG = ((CORE_PIN14_PORTREG & CORE_PIN14_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN14_DDRREG, CORE_PIN14_BIT) = 0;
	}
	inline void clr1() __attribute__((always_inline)) {
		CORE_PIN15_CONFIG = ((CORE_PIN15_PORTREG & CORE_PIN15_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN15_DDRREG, CORE_PIN15_BIT) = 0;
	}
	inline void clr2() __attribute__((always_inline)) {
		CORE_PIN16_CONFIG = ((CORE_PIN16_PORTREG & CORE_PIN16_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN16_DDRREG, CORE_PIN16_BIT) = 0;
	}
	inline void clr3() __attribute__((always_inline)) {
		CORE_PIN17_CONFIG = ((CORE_PIN17_PORTREG & CORE_PIN17_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN17_DDRREG, CORE_PIN17_BIT) = 0;
	}
	inline void clr4() __attribute__((always_inline)) {
		CORE_PIN18_CONFIG = ((CORE_PIN18_PORTREG & CORE_PIN18_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN18_DDRREG, CORE_PIN18_BIT) = 0;
	}
	inline void clr5() __attribute__((always_inline)) {
		CORE_PIN19_CONFIG = ((CORE_PIN19_PORTREG & CORE_PIN19_BITMASK)
		  ? CONFIG_PULLUP : CONFIG_NOPULLUP);
		GPIO_BITBAND(CORE_PIN19_DDRREG, CORE_PIN19_BIT) = 0;
	}
};

extern DDRCemulation DDRC;


#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7





#if 0
extern "C" {
void serial_print(const char *p);
void serial_phex(uint32_t n);
void serial_phex16(uint32_t n);
void serial_phex32(uint32_t n);
}
#endif


// SPI Control Register ­ SPCR
#define SPIE	7	// SPI Interrupt Enable - not supported
#define SPE	6	// SPI Enable
#define DORD	5	// DORD: Data Order
#define MSTR	4	// MSTR: Master/Slave Select
#define CPOL	3	// CPOL: Clock Polarity
#define CPHA	2	// CPHA: Clock Phase
#define SPR1	1	// Clock: 3 = 125 kHz, 2 = 250 kHz, 1 = 1 MHz, 0->4 MHz
#define SPR0	0
// SPI Status Register ­ SPSR
#define SPIF	7	// SPIF: SPI Interrupt Flag
#define WCOL	6	// WCOL: Write COLlision Flag - not implemented
#define SPI2X	0	// SPI2X: Double SPI Speed Bit
// SPI Data Register ­ SPDR

class SPCRemulation;
class SPSRemulation;
class SPDRemulation;

class SPCRemulation
{
public:
	inline SPCRemulation & operator = (int val) __attribute__((always_inline)) {
		uint32_t ctar, mcr, sim6;
		//serial_print("SPCR=");
		//serial_phex(val);
		//serial_print("\n");
		sim6 = SIM_SCGC6;
		if (!(sim6 & SIM_SCGC6_SPI0)) {
			//serial_print("init1\n");
			SIM_SCGC6 = sim6 | SIM_SCGC6_SPI0;
			SPI0_CTAR0 = SPI_CTAR_FMSZ(7) | SPI_CTAR_PBR(1) | SPI_CTAR_BR(1) | SPI_CTAR_CSSCK(1);
		}
		if (!(val & (1<<SPE))) {
			SPI0_MCR |= SPI_MCR_MDIS; // TODO: use bitband for atomic access
		}
		ctar = SPI_CTAR_FMSZ(7) | SPI_CTAR_PBR(1);
		if (val & (1<<DORD))  ctar |= SPI_CTAR_LSBFE;
		if (val & (1<<CPOL))  ctar |= SPI_CTAR_CPOL;
		if (val & (1<<CPHA)) {
			ctar |= SPI_CTAR_CPHA;
			if ((val & 3) == 0) {
				ctar |= SPI_CTAR_BR(1) | SPI_CTAR_ASC(1);
			} else if ((val & 3) == 1) {
				ctar |= SPI_CTAR_BR(4) | SPI_CTAR_ASC(4);
			} else if ((val & 3) == 2) {
				ctar |= SPI_CTAR_BR(6) | SPI_CTAR_ASC(6);
			} else {
				ctar |= SPI_CTAR_BR(7) | SPI_CTAR_ASC(7);
			}
		} else {
			if ((val & 3) == 0) {
				ctar |= SPI_CTAR_BR(1) | SPI_CTAR_CSSCK(1);
			} else if ((val & 3) == 1) {
				ctar |= SPI_CTAR_BR(4) | SPI_CTAR_CSSCK(4);
			} else if ((val & 3) == 2) {
				ctar |= SPI_CTAR_BR(6) | SPI_CTAR_CSSCK(6);
			} else {
				ctar |= SPI_CTAR_BR(7) | SPI_CTAR_CSSCK(7);
			}
		}
		ctar |= (SPI0_CTAR0 & SPI_CTAR_DBR);
		update_ctar(ctar);
		mcr = SPI_MCR_DCONF(0);
		if (val & (1<<MSTR)) mcr |= SPI_MCR_MSTR;
		if (val & (1<<SPE)) {
			mcr &= ~(SPI_MCR_MDIS | SPI_MCR_HALT);
			SPI0_MCR = mcr;
			enable_pins();
		} else {
			mcr |= (SPI_MCR_MDIS | SPI_MCR_HALT);
			SPI0_MCR = mcr;
			disable_pins();
		}
		//serial_print("MCR:");
		//serial_phex32(SPI0_MCR);
		//serial_print(", CTAR0:");
		//serial_phex32(SPI0_CTAR0);
		//serial_print("\n");
		return *this;
	}
	inline SPCRemulation & operator |= (int val) __attribute__((always_inline)) {
		uint32_t sim6;
		//serial_print("SPCR |= ");
		//serial_phex(val);
		//serial_print("\n");
		sim6 = SIM_SCGC6;
		if (!(sim6 & SIM_SCGC6_SPI0)) {
			//serial_print("init2\n");
			SIM_SCGC6 = sim6 | SIM_SCGC6_SPI0;
			SPI0_CTAR0 = SPI_CTAR_FMSZ(7) | SPI_CTAR_PBR(1) | SPI_CTAR_BR(1);
		}
		if (val & ((1<<DORD)|(1<<CPOL)|(1<<CPHA)|3)) {
			uint32_t ctar = SPI0_CTAR0;
			if (val & (1<<DORD)) ctar |= SPI_CTAR_LSBFE; // TODO: use bitband
			if (val & (1<<CPOL)) ctar |= SPI_CTAR_CPOL;
			if ((val & 3) == 1) {
				// TODO: implement - is this ever really needed
			} else if ((val & 3) == 2) {
				// TODO: implement - is this ever really needed
			} else if ((val & 3) == 3) {
				// TODO: implement - is this ever really needed
			}
			if (val & (1<<CPHA) && !(ctar & SPI_CTAR_CPHA)) {
				ctar |= SPI_CTAR_CPHA;
				// TODO: clear SPI_CTAR_CSSCK, set SPI_CTAR_ASC
			}
			update_ctar(ctar);
		}
		if (val & (1<<MSTR)) SPI0_MCR |= SPI_MCR_MSTR;
		if (val & (1<<SPE)) {
			SPI0_MCR &= ~(SPI_MCR_MDIS | SPI_MCR_HALT);
			enable_pins();
		}
		//serial_print("MCR:");
		//serial_phex32(SPI0_MCR);
		//serial_print(", CTAR0:");
		//serial_phex32(SPI0_CTAR0);
		//serial_print("\n");
		return *this;
	}
	inline SPCRemulation & operator &= (int val) __attribute__((always_inline)) {
		//serial_print("SPCR &= ");
		//serial_phex(val);
		//serial_print("\n");
		SIM_SCGC6 |= SIM_SCGC6_SPI0;
		if (!(val & (1<<SPE))) {
			SPI0_MCR |= (SPI_MCR_MDIS | SPI_MCR_HALT);
			disable_pins();
		}
		if ((val & ((1<<DORD)|(1<<CPOL)|(1<<CPHA)|3)) != ((1<<DORD)|(1<<CPOL)|(1<<CPHA)|3)) {
			uint32_t ctar = SPI0_CTAR0;
			if (!(val & (1<<DORD))) ctar &= ~SPI_CTAR_LSBFE; // TODO: use bitband
			if (!(val & (1<<CPOL))) ctar &= ~SPI_CTAR_CPOL;
			if ((val & 3) == 0) {
				// TODO: implement - is this ever really needed
			} else if ((val & 3) == 1) {
				// TODO: implement - is this ever really needed
			} else if ((val & 3) == 2) {
				// TODO: implement - is this ever really needed
			}
			if (!(val & (1<<CPHA)) && (ctar & SPI_CTAR_CPHA)) {
				ctar &= ~SPI_CTAR_CPHA;
				// TODO: set SPI_CTAR_ASC, clear SPI_CTAR_CSSCK
			}
			update_ctar(ctar);
		}
		if (!(val & (1<<MSTR))) SPI0_MCR &= ~SPI_MCR_MSTR;
		return *this;
	}
	inline int operator & (int val) const __attribute__((always_inline)) {
		int ret = 0;
		//serial_print("SPCR & ");
		//serial_phex(val);
		//serial_print("\n");
		if ((val & (1<<DORD)) && (SPI0_CTAR0 & SPI_CTAR_LSBFE)) ret |= (1<<DORD);
		if ((val & (1<<CPOL)) && (SPI0_CTAR0 & SPI_CTAR_CPOL)) ret |= (1<<CPOL);
		if ((val & (1<<CPHA)) && (SPI0_CTAR0 & SPI_CTAR_CPHA)) ret |= (1<<CPHA);
		if ((val & 3) == 3) {
			uint32_t dbr = SPI0_CTAR0 & 15;
			if (dbr <= 1) {
			} else if (dbr <= 4) {
				ret |= (1<<SPR0);
			} else if (dbr <= 6) {
				ret |= (1<<SPR1);
			} else {
				ret |= (1<<SPR1)|(1<<SPR0);
			}
		} else if ((val & 3) == 1) {
			// TODO: implement - is this ever really needed
		} else if ((val & 3) == 2) {
			// TODO: implement - is this ever really needed
		}
		if (val & (1<<SPE) && (!(SPI0_MCR & SPI_MCR_MDIS))) ret |= (1<<SPE);
		if (val & (1<<MSTR) && (SPI0_MCR & SPI_MCR_MSTR)) ret |= (1<<MSTR);
		//serial_print("ret = ");
		//serial_phex(ret);
		//serial_print("\n");
		return ret;
	}
	operator int () const __attribute__((always_inline)) {
		int ret = 0;
		if ((SIM_SCGC6 & SIM_SCGC6_SPI0)) {
			int ctar = SPI0_CTAR0;
			if (ctar & SPI_CTAR_LSBFE) ret |= (1<<DORD);
			if (ctar & SPI_CTAR_CPOL) ret |= (1<<CPOL);
			if (ctar & SPI_CTAR_CPHA) ret |= (1<<CPHA);
			ctar &= 15;
			if (ctar <= 1) {
			} else if (ctar <= 4) {
				ret |= (1<<SPR0);
			} else if (ctar <= 6) {
				ret |= (1<<SPR1);
			} else {
				ret |= (1<<SPR1)|(1<<SPR0);
			}
			int mcr = SPI0_MCR;
			if (!(mcr & SPI_MCR_MDIS)) ret |= (1<<SPE);
			if (mcr & SPI_MCR_MSTR) ret |= (1<<MSTR);
		}
		return ret;
	}
	friend class SPSRemulation;
private:
	static inline void update_ctar(uint32_t ctar) __attribute__((always_inline)) {
		if (SPI0_CTAR0 == ctar) return;
		uint32_t mcr = SPI0_MCR;
		if (mcr & SPI_MCR_MDIS) {
			SPI0_CTAR0 = ctar;
		} else {
			SPI0_MCR = mcr | SPI_MCR_MDIS | SPI_MCR_HALT;
			SPI0_CTAR0 = ctar;
			SPI0_MCR = mcr;
		}
	}
	inline void enable_pins(void) __attribute__((always_inline)) {
		//serial_print("enable_pins\n");
		CORE_PIN11_CONFIG = PORT_PCR_DSE | PORT_PCR_MUX(2);
		CORE_PIN12_CONFIG = PORT_PCR_MUX(2);
		CORE_PIN13_CONFIG = PORT_PCR_DSE | PORT_PCR_MUX(2);
	}
	inline void disable_pins(void) __attribute__((always_inline)) {
		//serial_print("disable_pins\n");
		CORE_PIN11_CONFIG = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
		CORE_PIN12_CONFIG = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
		CORE_PIN13_CONFIG = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
	}
};
extern SPCRemulation SPCR;

class SPSRemulation
{
public:
	inline SPSRemulation & operator = (int val) __attribute__((always_inline)) {
		//serial_print("SPSR=");
		//serial_phex(val);
		//serial_print("\n");
		uint32_t ctar = SPI0_CTAR0;
		if (val & (1<<SPI2X)) {
			ctar |= SPI_CTAR_DBR;
		} else {
			ctar &= ~SPI_CTAR_DBR;
		}
		SPCRemulation::update_ctar(ctar);
		//serial_print("MCR:");
		//serial_phex32(SPI0_MCR);
		//serial_print(", CTAR0:");
		//serial_phex32(SPI0_CTAR0);
		//serial_print("\n");
		return *this;
	}
	inline SPSRemulation & operator |= (int val) __attribute__((always_inline)) {
		//serial_print("SPSR |= ");
		//serial_phex(val);
		//serial_print("\n");
		if (val & (1<<SPI2X)) SPCRemulation::update_ctar(SPI0_CTAR0 |= SPI_CTAR_DBR);
		return *this;
	}
	inline SPSRemulation & operator &= (int val) __attribute__((always_inline)) {
		//serial_print("SPSR &= ");
		//serial_phex(val);
		//serial_print("\n");
		if (!(val & (1<<SPI2X))) SPCRemulation::update_ctar(SPI0_CTAR0 &= ~SPI_CTAR_DBR);
		return *this;
	}
	inline int operator & (int val) const __attribute__((always_inline)) {
		int ret = 0;
		//serial_print("SPSR & ");
		//serial_phex(val);
		//serial_print("\n");
		// TODO: using SPI_SR_TCF isn't quite right.  Control returns to the
		// caller after the final edge that captures data, which is 1/2 cycle
		// sooner than AVR returns.  At 500 kHz and slower SPI, this can make
		// a difference when digitalWrite is used to manually control the CS
		// pin, and perhaps it could matter at high clocks if faster register
		// access is used?  But does it really matter?  Do any SPI chips in
		// practice really perform differently if CS negates early, after the
		// final bit is clocked, but before the end of the whole clock cycle?
		if ((val & (1<<SPIF)) && (SPI0_SR & SPI_SR_TCF)) ret = (1<<SPIF);
		if ((val & (1<<SPI2X)) && (SPI0_CTAR0 & SPI_CTAR_DBR)) ret |= (1<<SPI2X);
		//delayMicroseconds(50000);
		return ret;
	}
	operator int () const __attribute__((always_inline)) {
		int ret = 0;
		//serial_print("SPSR (int)\n");
		if (SPI0_SR & SPI_SR_TCF) ret = (1<<SPIF);
		if (SPI0_CTAR0 & SPI_CTAR_DBR) ret |= (1<<SPI2X);
		return ret;
	}
};
extern SPSRemulation SPSR;

class SPDRemulation
{
public:
	inline SPDRemulation & operator = (int val) __attribute__((always_inline)) {
		//serial_print("SPDR = ");
		//serial_phex(val);
		//serial_print("\n");
		SPI0_MCR |= SPI_MCR_CLR_RXF; // discard any received data
		SPI0_SR = SPI_SR_TCF;
		//SPI0_SR = SPI_SR_EOQF;
		//SPI0_PUSHR = (val & 255) | SPI0_PUSHR_EOQ;
		SPI0_PUSHR = (val & 255);
		return *this;
	}
	operator int () const __attribute__((always_inline)) {
		uint32_t val;
		val = SPI0_POPR & 255;
		//serial_print("SPDR (int) ");
		//serial_phex(val);
		//serial_print("\n");
		return val;
	}
};
extern SPDRemulation SPDR;


class SREGemulation
{
public:
	operator int () const __attribute__((always_inline)) {
		uint32_t primask;
		asm volatile("mrs %0, primask\n" : "=r" (primask)::);
		if (primask) return 0;
		return (1<<7);
	}
	inline SREGemulation & operator = (int val) __attribute__((always_inline)) {
		if (val & (1<<7)) {
			__enable_irq();
		} else {
			__disable_irq();
		}
		return *this;
	}
};
extern SREGemulation SREG;

// these are not intended for public consumption...
#undef GPIO_BITBAND_ADDR
#undef GPIO_BITBAND
#undef CONFIG_PULLUP
#undef CONFIG_NOPULLUP

#endif // __cplusplus

#endif
