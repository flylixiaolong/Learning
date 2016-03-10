#!/usr/bin/env python

from gi.repository import Gtk, Gio
from gi.repository import EvinceDocument
from gi.repository import EvinceView

class HelloWorldApp(Gtk.Application):
   def __init__(self):
       Gtk.Application.__init__(self, application_id="apps.test.helloevince", flags=Gio.ApplicationFlags.FLAGS_NONE)
       self.connect("activate", self.on_activate)

   def on_activate(self, data=None):
       window = Gtk.Window(type=Gtk.WindowType.TOPLEVEL)
       window.set_title("Evince Gtk3 Python Example")
       window.set_border_width(24)
       scroll = Gtk.ScrolledWindow()
       window.add(scroll)
       EvinceDocument.init()
       doc = EvinceDocument.Document.factory_get_document('file:///home/user/test.pdf')
       view = EvinceView.View()
       model = EvinceView.DocumentModel()
       model.set_document(doc)
       view.set_model(model)
       scroll.add(view)
       window.show_all()
       self.add_window(window)

if __name__ == "__main__":
   app = HelloWorldApp()
   app.run(None)
