import paho.mqtt.client as mqtt_client
import random
import time

broker="broker.emqx.io"

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print("Failed to connect, return code %d\n", rc)

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_connect = on_connect
client.connect(broker)

seconds = 20

state = "u"
client.publish("esp8266-ff55/command", state)
print(f"publish state is {state}")
time.sleep(20)
for _ in range(60):
    state = "d"
    client.publish("esp8266-ff55/command", state)
    print(f"publish state is {state}")
    time.sleep(seconds)
    print(seconds)
    
    state = "u"
    client.publish("esp8266-ff55/command", state)
    print(f"publish state is {state}")
    time.sleep(60-seconds)
    
    if seconds == 10:
        seconds = 20
    else:
        seconds -= 1

client.disconnect()