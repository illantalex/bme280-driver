# BME280 

A Linux device driver written for the Bosch BME280 

## Setup 

This driver was tested on a Raspberry Pi 4B. To run on Raspberry Pi OS:

Run `raspi config` and enable `Interface Options -> I2C`

Build the driver:
```
cd driver && make
```

Upon successfully building, the kernel module `bme280.ko` will be created.

To initialize the driver, run 
```
sudo insmod bme280.ko
```

A device file should now be created in `/dev/bme280`. You can read measurements
by running 
```
chmod 666 /dev/bme280 # enable read access
cat < /dev/bme280
```

The data format of a single reading will be given in the order of temperature, pressure, and
humidity
```
T2920P24874300H27597
```

To interpret the data:
- Temperature is in Celsius and is accurate to two decimal places: e.g.
  `2920->29.20C`
- Pressure is in Pa and is obtained by dividing the value by 256, accurate to
  two decimal places, e.g. `24874300/256=97165.23 Pa`
- Humidity is in percentage and is obtained by dividng the value by 1024, e.g.
  `27597/1024=25.9`


To remove the driver, run 
```
sudo rmmod bme280
```
