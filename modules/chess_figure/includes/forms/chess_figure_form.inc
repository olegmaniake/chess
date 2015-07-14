<?php
function chess_figure_form(){
  $form['chess_figure'] = array(
    '#type' => 'select',
    '#title' => t('chess figure'),
    '#default_value' => variable_get('chess_figure','3'),
    '#description'=> t('selection chess figure'),
  );
  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('select color of figure'),
    '#description' => '',
    '#default value' => variable_get('color','1'),
    '#options' => array(
      'black' => 'black',
      'white' => 'white',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#weigth' => 50,
    '#value' => t('Create new game'),
  );
  $form['#submit'] = array('chess_figure_form_submit');

  $types = chess_figure_get_types();
  foreach ($types as $type => $figure){
    $form['chess_figure']['#options'][$type] = $figure;
  }
  return $form;
}

function chess_figure_form_submit($form,&$form_state){
  $values = array(
    'type' => $form_state['values']['chess_figure'],
    'color' => $form_state['values']['color'],
    'cell_x' => 1,
    'cell_y' => 1,
  );
  $figure = entity_get_controller('chess_figure')->create($values);
  $figure->save();
  $form_state['redirect'] = 'chess/figure/'.$figure->fid;
}