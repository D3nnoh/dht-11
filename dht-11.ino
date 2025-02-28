#include <DHT.h>

// Define the pin where the DHT11 sensor is connected
#define DHTPIN 2  // Change this if using a different pin

// Define the sensor type (DHT11)
#define DHTTYPE DHT11

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("DHT11 Temperature and Humidity Sensor");
  
  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  // Wait a short time before getting new readings
  delay(2000); 

  // Get temperature and humidity readings
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Default is Celsius
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Print values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Optional: Uncomment the next line to print temperature in Fahrenheit
  // Serial.print("Temperature: "); Serial.print(dht.readTemperature(true)); Serial.println(" °F");
}
