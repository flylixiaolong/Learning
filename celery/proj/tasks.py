from .celery import app


@app.task
def add(x, y):
    result  = x+y
    return result

