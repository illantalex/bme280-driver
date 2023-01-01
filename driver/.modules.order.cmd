cmd_/home/pi/Documents/bme280/driver/modules.order := {   echo /home/pi/Documents/bme280/driver/bme280.ko; :; } | awk '!x[$$0]++' - > /home/pi/Documents/bme280/driver/modules.order
