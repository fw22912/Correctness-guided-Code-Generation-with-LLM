import asyncio
import threading
import requests
import time

class APIMonitor:
    def __init__(self, api_url, check_interval=60):
        self.api_url = api_url
        self.check_interval = check_interval
        self.last_update_time = None
        self.is_running = False
        self.thread = None
        self.on_update = None
        
    def start(self):
        self.is_running = True
        self.thread = threading.Thread(target=self._monitor_loop)
        self.thread.start()
        
    def stop(self):
        self.is_running = False
        
    def _monitor_loop(self):
        while self.is_running:
            response = requests.get(self.api_url)
            if response.status_code == 200:
                data = response.json()
                update_time = data.get("posts")[0]
                if self.last_update_time==None:
                    self.last_update_time = update_time
                if update_time != self.last_update_time:
                    self.last_update_time = update_time
                    if self.on_update:
                        asyncio.run(self.on_update(update_time))
            else:
                print(f"API request failed with status code {response.status_code}")
            time.sleep(self.check_interval)
            
def onpost( on_update=None):
    monitor = APIMonitor('https://api.cbmc.club/v1/latest?limit=1', 10)
    monitor.on_update = on_update
    monitor.start()

def post_list(limit:int):
    if int(limit) > 300:
        limit=300
    url=f"https://api.cbmc.club/v1/latest?limit={str(limit)}"
    a=requests.get(url)
    return a.json()

def get_post(platformId:int):
    url=f"https://api.cbmc.club/v1/post/{platformId}"
    a=requests.get(url)
    if a.json()["status"] == 'failed':
        return None
    else:
        return a.json()