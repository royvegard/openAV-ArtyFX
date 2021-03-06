// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "masha_widget.h"

void MashaUI::cb_headerImage_i(Avtk::Image*, void*) {
  //system("xdg-open http://www.openavproductions.com/artyfx#ducka");
}
void MashaUI::cb_headerImage(Avtk::Image* o, void* v) {
  ((MashaUI*)(o->parent()->user_data()))->cb_headerImage_i(o,v);
}

void MashaUI::cb_graph_i(Avtk::Masher* o, void*) {
  //cutoff = o->value();
//float g = o->getGain();
//gainDial->value( g );
//freq->value( cutoff ); // update dial
//writePort(CUTOFF_FREQ, cutoff);
float tmp = o->getActive();
writePort(MASHA_ACTIVE, tmp );
//printf("masha UI active %f\n" , tmp);
}
void MashaUI::cb_graph(Avtk::Masher* o, void* v) {
  ((MashaUI*)(o->parent()->user_data()))->cb_graph_i(o,v);
}

void MashaUI::cb_time_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->duration( tmp );
writePort( int(MASHA_TIME), tmp );
}
void MashaUI::cb_time(Avtk::Dial* o, void* v) {
  ((MashaUI*)(o->parent()->user_data()))->cb_time_i(o,v);
}

void MashaUI::cb_volume_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->volume( tmp );
writePort( int(MASHA_AMP), tmp );
}
void MashaUI::cb_volume(Avtk::Dial* o, void* v) {
  ((MashaUI*)(o->parent()->user_data()))->cb_volume_i(o,v);
}

void MashaUI::cb_replace_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->replace( tmp );
writePort( int(MASHA_DRY_WET),tmp );
}
void MashaUI::cb_replace(Avtk::Dial* o, void* v) {
  ((MashaUI*)(o->parent()->user_data()))->cb_replace_i(o,v);
}

/**
   if the type of filter changes, this function will highlight the right button
*/
void MashaUI::update_button(int button) {
}

MashaUI::MashaUI() {
  { Fl_Double_Window* o = window = new Fl_Double_Window(160, 220);
    window->user_data((void*)(this));
    { headerImage = new Avtk::Image(0, 0, 160, 29, "header.png");
      headerImage->box(FL_NO_BOX);
      headerImage->color(FL_BACKGROUND_COLOR);
      headerImage->selection_color(FL_BACKGROUND_COLOR);
      headerImage->labeltype(FL_NORMAL_LABEL);
      headerImage->labelfont(0);
      headerImage->labelsize(14);
      headerImage->labelcolor((Fl_Color)20);
      headerImage->callback((Fl_Callback*)cb_headerImage);
      headerImage->align(Fl_Align(FL_ALIGN_CENTER));
      headerImage->when(FL_WHEN_RELEASE_ALWAYS);
      headerImage->setPixbuf(header.pixel_data,4);
    } // Avtk::Image* headerImage
    { graph = new Avtk::Masher(5, 36, 150, 126, "graph");
      graph->box(FL_UP_BOX);
      graph->color((Fl_Color)179);
      graph->selection_color(FL_INACTIVE_COLOR);
      graph->labeltype(FL_NO_LABEL);
      graph->labelfont(0);
      graph->labelsize(14);
      graph->labelcolor(FL_FOREGROUND_COLOR);
      graph->callback((Fl_Callback*)cb_graph);
      graph->align(Fl_Align(FL_ALIGN_BOTTOM));
      graph->when(FL_WHEN_CHANGED);
    } // Avtk::Masher* graph
    { time = new Avtk::Dial(113, 169, 37, 37, "Time");
      time->box(FL_NO_BOX);
      time->color((Fl_Color)90);
      time->selection_color(FL_INACTIVE_COLOR);
      time->labeltype(FL_NORMAL_LABEL);
      time->labelfont(0);
      time->labelsize(10);
      time->labelcolor(FL_FOREGROUND_COLOR);
      time->callback((Fl_Callback*)cb_time);
      time->align(Fl_Align(FL_ALIGN_BOTTOM));
      time->when(FL_WHEN_CHANGED);
      time->value(0.5);
    } // Avtk::Dial* time
    { volume = new Avtk::Dial(10, 169, 37, 37, "Vol");
      volume->box(FL_NO_BOX);
      volume->color((Fl_Color)90);
      volume->selection_color(FL_INACTIVE_COLOR);
      volume->labeltype(FL_NORMAL_LABEL);
      volume->labelfont(0);
      volume->labelsize(10);
      volume->labelcolor(FL_FOREGROUND_COLOR);
      volume->callback((Fl_Callback*)cb_volume);
      volume->align(Fl_Align(FL_ALIGN_BOTTOM));
      volume->when(FL_WHEN_CHANGED);
      volume->value(1);
    } // Avtk::Dial* volume
    { replace = new Avtk::Dial(62, 169, 37, 37, "PassThru");
      replace->box(FL_NO_BOX);
      replace->color((Fl_Color)90);
      replace->selection_color(FL_INACTIVE_COLOR);
      replace->labeltype(FL_NORMAL_LABEL);
      replace->labelfont(0);
      replace->labelsize(10);
      replace->labelcolor(FL_FOREGROUND_COLOR);
      replace->callback((Fl_Callback*)cb_replace);
      replace->align(Fl_Align(FL_ALIGN_BOTTOM));
      replace->when(FL_WHEN_CHANGED);
      replace->value(1);
    } // Avtk::Dial* replace
    window->color( fl_rgb_color( 17,17,17) );
    close_cb( o, 0 );
    window->end();
  } // Fl_Double_Window* window
}

void MashaUI::idle() {
  Fl::check();
  Fl::flush();
}

int MashaUI::getWidth() {
  return window->w();
}

int MashaUI::getHeight() {
  return window->h();
}

void MashaUI::writePort(int port, float& value) {
  //cout << "port " << port << " value " << value << endl;
  write_function(controller, port, sizeof(float), 0, &value);
}

void close_cb(Fl_Widget* o, void*) {
  if ((Fl::event() == FL_KEYDOWN || Fl::event() == FL_SHORTCUT) && Fl::event_key() == FL_Escape)
    {
      return; // ignore ESC
    }
    else
    {
      o->hide();
    }
}
