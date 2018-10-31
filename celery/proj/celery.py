from celery import Celery

app = Celery(include="proj.tasks")

app.conf.beat_schedule = {
    'add-every-30-seconds': {
        'task': 'proj.tasks.add',
        'schedule': 5.0,
        'args': (16, 16)
    },
}
app.conf.timezone = 'UTC'

@app.on_after_configure.connect
def setup_periodic_tasks(sender, **kwargs):
    sender.add_periodic_task(5.0, test.s('hello'), name='add every 10')

@app.task
def test(s):
    print(s)
    return s
