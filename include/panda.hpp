class Panda
{

private: // set line
  void set_xline(t_bunny_position *pos, unsigned int color);
  void set_yline(t_bunny_position *pos, unsigned int color);
  void set_eline(t_bunny_position *pos, unsigned int color);
  void set_pandelium(t_bunny_position pos, int radius, int nbr);


  
public:

  int l = 1;
  bool end = true;
  
  t_bunny_window *_win;
  t_bunny_pixelarray *_px;
  
public:
  Panda(int, int, char *);
  ~Panda(void);

  void clear(unsigned int color);
  int getWidth() const;
  int getHeight() const;

  void set_pixel(int i, unsigned int color);  
  void set_pixel (int, int, unsigned int);
  void set_pixel(t_bunny_position pos, unsigned int color);
  void set_pixel(t_bunny_accurate_position pos, unsigned int color);
  void set_line(t_bunny_position *pos, unsigned int color);
  void set_line(t_bunny_position pa, t_bunny_position pb, unsigned int color);
  
  unsigned char color_ratiod(unsigned char from, unsigned char to, double ratio);
  unsigned int mix_color (unsigned int ca, unsigned int cb, double percent);
  double color_ratio(int value, int min, int max);
  void vgradiant(unsigned int ca, unsigned int cb);

  unsigned int get_pixel(t_bunny_position pos);
  unsigned int get_pixel(t_bunny_accurate_position pos);



  void set_square (t_bunny_position *pos, unsigned int color);
  void whirlpool(t_bunny_position *pos, double prog, int depth);
  void whirlpool(t_bunny_position *pos, double prog, int depth, unsigned int color);
  void whirlpool_alpha(t_bunny_position *pos, double prog, int depth);
  void whirlpool_alpha(t_bunny_position *pos, double prog, int depth, unsigned int color);
  
};

t_bunny_response __loop (void *);
t_bunny_response __display(void *);
t_bunny_response event_handler(t_bunny_event_state, t_bunny_keysym, void *);
