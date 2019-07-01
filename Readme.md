# C++ Project building, testing and Docker image creating with Docker executor on a local Gitlab server
## Step 0: 
- Install docker for your OS (Windows, macOS or Linux)
- Install Gitlab CE and Gitlab-Runner for your OS or you can use Gitlab docker images, if no install is available (Windows, macOS)
- Register Gitlab runners for your Gitlab server (yu need your Gitlab server URL and token)
- I use 2 Gitlab runners: 
    - A runner for building and testing the project (tags: cxx, )
    - A runner for building project Docker image

Here is my runners /etc/gitlab-runner/config.toml:
```toml
concurrent = 1
check_interval = 0

[session_server]
  session_timeout = 1800

[[runners]]
  name = "local-runner"
  url = "http://ubudesk/"
  token = "Ye-Fds4-gUATLH85Vkwp"
  executor = "docker"
  [runners.custom_build_dir]
  [runners.docker]
    tls_verify = false
    image = "ubuntu:18.04"
    privileged = false
    disable_entrypoint_overwrite = false
    oom_kill_disable = false
    disable_cache = false
    volumes = ["/cache"]
    pull_policy = "if-not-present"
    shm_size = 0
  [runners.cache]
    [runners.cache.s3]
    [runners.cache.gcs]

[[runners]]
  name = "docker-deploy"
  url = "http://ubudesk/"
  token = "fgLYQhZG-ndwffxXZ7As"
  executor = "docker"
  [runners.custom_build_dir]
  [runners.docker]
    tls_verify = false
    image = "docker:stable"
    privileged = false
    disable_entrypoint_overwrite = false
    oom_kill_disable = false
    disable_cache = false
    volumes = ["/var/run/docker.sock:/var/run/docker.sock", "/cache"]
    shm_size = 0
    pull_policy = "if-not-present"
  [runners.cache]
    [runners.cache.s3]
    [runners.cache.gcs]
```
## Step 1: Build Docker GCC build image (tagged alpine-gcc:3.9)
```bash
bash
docker build -t alpine-gcc:3.9 -f Dockerfile.build .
```

## C++ Project development:
- Modify the project and push changes to Gitlab server. 
- Gitlab server will run your CI/CD stages:
    - build: build your C++ project
    - test: test your C++ project
    - image: create Docker image
- A Docker image will be created and tagged helloapp:latest, you can test it by:
```bash
bash
docker run helloapp:latest
```
- The output:
```text
Hello World!
```
## Todo 
- Add a stage to deploy your Docker image to a server, Docker hub, etc...