# Morse-Code-Converter

The microcontroller that was selected was the STM32F4-Discovery board. The reason this was
selected was because of the external components needed. In this case the external components were 2
GPIO buttons and an LED screen to display the characters that were the result of the Morse code
conversion. The STM32F4 was selected over the ARM Cortex A9 DE10 Standard simulator as no GPIO
buttons were present nor LED screen to map the characters onto a display. Due to this we thought that the
best route to go was the STM32F4. Even though this microcontroller comes with a STM32_HAL, bare
metal is still achievable. However, it is not feasible to code the entire bare-metal functionality for an LED
screen. The GPIO buttons were set up using bare-metal functionality to identify if the user has encoded a
dot or a dash. Secondly, the STM32F4 was readily available to us and we were able to connect an LED
screen and two GPIO buttons to test the functionality of the system. However, due to the situation using
the simulator for the ARM Cortex A9 DE10 board there was no way to connect two GPIO buttons and an
LED screen.

Performance was not considered heavily when selecting between the STM32F4 and the ARM
Cortex A9 DE10 board as both microcontrollers have much higher performance than needed. This is since
the system is coded in such a way that also utilizes performance. By using interrupts, the CPU is asleep
most of the time while the system is running and turns on when a user has encoded a dot or a dash. In
terms of getting the system manufactured and releasing it to the market a cost-effective CPU was
necessary. With this necessity in mind it was clear an STM32F4 CPU was not feasible as it is priced
around $20 and the consumer would utilize less than half of the potential performance. Instead a 16 pin
GPIO such as the Texas Instrument PCF8574AN would most likely be used which costs around $2 and
with that two GPIO push buttons which are around $1 and an LED screen ranging from $1 - $3 coming to
a total cost of $7. This would be the most feasible solution and make the system cost friendly for the end
consumer.