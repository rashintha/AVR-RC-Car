# AVR RC Car

This is a AVR code for RC car controlled with Serial. Code is compatible with both Atmega32A and Atmega328P MCUs. So Arduino UNO and Arduino NANO is also working fine with this project.

## Getting Started

### Header Files

#### cpu_def.h
This header file contains all the definitions of used registers and pins of Atmega32A and Atmega328P. If you need to port this to other AVR mcu, change definitions here accordingly.

#### serial.h
This header file is used to do communication with serial port. Change **BAUD_RATE** if you need to change the baud rate of usart.

#### pwm.h
This header file is used to do all the PWM generations.

## Authors

* **Rashintha Maduneth** - *Creating the system*

See also the list of [contributors](https://github.com/pixy-avr/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* USART Library

## Special Thanks

* [Dr. Hiran Jayaweera](http://science.cmb.ac.lk/physics/academic_staff/dr-hiran-h-e-jayaweera/)
* [Mr. Deshitha Wickramarathna](http://science.cmb.ac.lk/physics/academic_staff/mr-d-d-c-wickramarathna/)
* Department of Physics at the Faculty of Science, University of Colombo, Sri Lanka.
