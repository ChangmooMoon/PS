import requests, json

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


def simulationReq(truckAcion):
    return requests.put(
        BASE_URL + "/simulate",
        headers={"Authorization: auth_key"},
        data=json.dumps(truckAction),
    )


dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]


def init(problem):
    startReq = requests.post(
        BASE_URL + "/start", headers=headers, params={"problem": problem}
    ).json()
    auth_key = startReq["auth_key"]

    truckLen = 5 if problem == 1 else 10
    boardLen = 5 if problem == 1 else 60
    truck = [0] * truckLen  # 보유바이크수
    # truckPos = [0] * truckLen  # id위치
	# board = [[0] * boardLen] * boardLen  # 바이크배치
    board = list(i['located_bikes_count'] for i in locationsReq()['locations'])
    print(board)

    # for i in range(0, 43200, 6):
    # if(i % 60 == 0) simulationReq(truckAction)


init(1)
