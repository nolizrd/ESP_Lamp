import paho.mqtt.client as mqtt_client
import random
import time

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_connect = on_connect
client.connect(broker)

seconds = 20
for _ in range(60):
    state = "on" if 20 <= seconds <= 40 else "off"
    client.publish("esp8266-fc6f/command", state)
    print(f"publish state is {state}")
    time.sleep(seconds)
    if seconds == 10:
        seconds = 20
    else:
        seconds -= 1

client.disconnect()