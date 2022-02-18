#include <Wire.h>
#include <Multichannel_Gas_GMXXX.h>

// if you use the software I2C to drive the sensor, you can uncommnet the define SOFTWAREWIRE which in Multichannel_Gas_GMXXX.h.
#ifdef SOFTWAREWIRE
    #include <SoftwareWire.h>
    SoftwareWire myWire(3, 2);
    GAS_GMXXX<SoftwareWire> gas;
#else
    #include <Wire.h>
    GAS_GMXXX<TwoWire> gas;
#endif

class GroveMultiChannelGasV2 : public PollingComponent {
    public:

        Sensor *co_sensor = new Sensor();
        Sensor *no2_sensor = new Sensor();
        Sensor *c2h5oh_sensor = new Sensor();
        Sensor *voc_sensor = new Sensor();

        GroveMultiChannelGasV2() : PollingComponent(15000) {}

        void setup() override {
     	    Serial.begin(9600);
	    gas.begin(Wire, 0x08);
        }

        void update() override {

            float co;
            co = gas.measure_CO();
            if (co >= 0) co_sensor->publish_state(gas.calcVol(co));

            float no2;
            no2 = gas.measure_NO2();
            if (no2 >= 0) no2_sensor->publish_state(gas.calcVol(no2));

            float c2h5oh;
            c2h5oh = gas.measure_C2H5OH();
            if (c2h5oh >= 0) c2h5oh_sensor->publish_state(gas.calcVol(c2h5oh));

            float voc;
            voc = gas.measure_VOC();
            if (voc >= 0)  voc_sensor->publish_state(gas.calcVol(voc));


        }
};


