# hw2

## windows

```powershell
docker run --rm -it -p 16788:16788 -v ${pwd}:/source twyair/safot-hw:2
```

## linux

```powershell
docker run --rm -it -p 16788:16788 -v $(pwd):/source twyair/safot-hw:2
```

you may need to use `sudo`

## jupyter server

```bash
source start-jupyter &
```

open <http://127.0.0.1:16788/lab>
