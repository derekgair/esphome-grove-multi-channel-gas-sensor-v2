# esphome-grove-multi-channel-gas-sensor-v2
Esphome - Grove Multichannel Gas Sensor V2

### Installation

1. Add the GroveMultiChannelGasV2.cpp.h file to the Esphome config directory.
2. Add the following entry to the ```esphome:``` block in the yaml file:

```
  includes:
    - "GroveMultiChannelGasV2.cpp.h"
  libraries:
    - "Wire"
    - "https://github.com/Seeed-Studio/Seeed_Arduino_MultiGas"
```

3. Add the following sensor values under ```sensor:``` block in the yaml file:

```
  - platform: custom
    lambda: |-
      auto my_sensor = new GroveMultiChannelGasV2();
      App.register_component(my_sensor);
      return {my_sensor->co_sensor, my_sensor->no2_sensor, my_sensor->c2h5oh_sensor, my_sensor->voc_sensor};
    sensors:
      - name: "CO Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'ppm'
      - name: "NO2 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'µg/m³'
      - name: "C2H5OH Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'ppm'
      - name: "VOC Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'ppm'
```

### Calibration and values.


