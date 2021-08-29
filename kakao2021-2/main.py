import requests, json
from pprint import pprint

BASE_URL = "https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users"
X_AUTH_TOKEN = "150ef4a54a904fdda8fd3207f5277781"
headers = {"Content_type": "application/json", "X-Auth-Token": X_AUTH_TOKEN}


def locationsReq(key):
    return requests.get(
        BASE_URL + "/locations", headers={"Authorization": key}
    ).json()  # locations: [{id, located_bikes_count},{}, ...]


def trucksReq(key):
    return requests.get(
        BASE_URL + "/trucks", headers={"Authorization": key}
    ).json()  # trucks: [{id, location_id, loaded_bikes_count}]


def scoreReq(key):
    return requests.get(
        BASE_URL + "/score", headers={"Authorization": key}
    ).json()  # score


def simulationReq(auth_key, truckCmd):
    return requests.put(
        BASE_URL + "/simulate",
        headers={"Authorization": auth_key},
        json=dict(commands=truckCmd),
    ).json()


def init(problem):
    startReq = requests.post(
        BASE_URL + "/start", headers=headers, params={"problem": problem}
    ).json()
    auth_key = startReq["auth_key"]

    locations = locationsReq(auth_key)["locations"]
    trucks = trucksReq(auth_key)["trucks"]

    with open("s1.json") as f:
        json_data = json.load(f)

    for i in range(720):
        res = simulationReq(auth_key, [])
        pprint(res)

    score = scoreReq(auth_key)
    pprint(score)


init(1)
