cmd_/home/pi/Documents/bme280/c/modules.order := {   echo /home/pi/Documents/bme280/c/bme280.ko; :; } | awk '!x[$$0]++' - > /home/pi/Documents/bme280/c/modules.order
