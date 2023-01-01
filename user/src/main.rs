extern crate tokio;

use std::fs::File;
use std::io::{self, prelude::*, BufReader};

struct SensorReading {
    temperature: f64,
    pressure: f64,
    humidity: f64,
}

impl SensorReading {
    // Parses a sensor line to get temperature, pressure, and humidity values
    // line is expected to be in the format "T{num}P{num}H{num}"
    fn new(line: &String) -> SensorReading {
        let mut vec1 = vec![0, 0, 0];

        let mut tempStr = Vec::new();
        let mut pressureStr = Vec::new();
        let mut humidityStr = Vec::new();

        let mut strs = vec![tempStr, pressureStr, humidityStr];

        let mut i = 0;
        for c in line.chars() {
            match c {
                'T' => continue,
                'P' | 'H' => i += 1,
                _ => strs[i].push(c),
            }
        }
        for (j, v) in strs.into_iter().enumerate() {
            vec1[j] = v.iter().collect::<String>().parse::<i32>().unwrap();
        }
        // Apply conversion for temperature / pressure / humidity
        return SensorReading {
            temperature: (vec1[0] as f64) / 100.0,
            pressure: (vec1[1] as f64) / 256.0,
            humidity: (vec1[2] as f64) / 1024.0,
        };
    }
}

fn main() -> io::Result<()> {
    // Open device file
    let mut file = File::open("/dev/bme280")?;
    let reader = BufReader::new(file);

    // Since the device file is a stream, this loop will run forever
    for line in reader.lines() {
        match line {
            Ok(line) => {
                let x = SensorReading::new(&line);
                println!("Temperature: {:.2} Pressure: {:.2} Humidity: {:.2}\n");
            }
            Err(e) => println!("ERROR: {}", e),
        }
    }

    Ok(())
}
