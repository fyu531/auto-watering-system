// 定义湿度传感器引脚
#define MOISTURE_SENSOR A0
// 定义继电器控制引脚
#define RELAY_PIN 9

// 设置湿度阈值（根据实际情况调整）
const int moistureThreshold = 3000;  // 湿度低于300时浇水
// 设置浇水持续时间（单位：毫秒）
const int wateringDuration = 4000;  // 浇水35秒

void setup() {
    // 初始化湿度传感器引脚为输入
    pinMode(MOISTURE_SENSOR, INPUT);
    // 初始化继电器控制引脚为输出
    pinMode(RELAY_PIN, OUTPUT);
    // 初始化串口通信
    Serial.begin(9600);
}

void loop() {
    // 读取湿度传感器的值
    int moistureValue = analogRead(MOISTURE_SENSOR);
    // 打印湿度值到串口监视器
    Serial.println(moistureValue);
//    digitalWrite(RELAY_PIN,LOW);
    // 判断是否需要浇水
    if (moistureValue < moistureThreshold) {
        // 启动水泵
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("开始浇水...");
        // 等待浇水持续时间
        delay(wateringDuration);
        // 关闭水泵
        digitalWrite(RELAY_PIN, LOW);
        Serial.println("浇水完成！");
    }
    
    // 延时1秒后再次检测
    delay(4000);
}
