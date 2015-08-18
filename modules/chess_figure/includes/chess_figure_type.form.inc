<?php

function chess_figure_type_form($form, &$form_state, $chess_figure_type , $op ){
  if ($op == 'edit'){
    $def = chess_figure_type_edit_default($chess_figure_type);
  } else {
    $def = chess_figure_type_add_default();
  }


  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $def['label'],
    '#description' => t('The human name of this type.'),
    '#required' =>TRUE,
    '#sieze' => 50,
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => $def['type'],
    '#maxlength' => 25,
    '#machine_name' => array(
      'exist' => 'chess_figure_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this chess figure type. It must only contain lowercase letters, numbers, and underscores.')
  );

  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Descrption'),
    '#default_value' => $def['description']
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#waigth' => 50,
    '#value' => t('Create chess figure'),
  );
  $form['#submit'] = 'chess_figure_type_form_submit';
  return $form;
}

function chess_figure_type_edit_default($figure_type){
   $return['label'] = $figure_type->label;
    $return['type'] =  $figure_type->type;
    $return['description'] = $figure_type-> description;

  return $return;
}

function chess_figure_type_add_default(){
  return array(
    'label' => 'enter label',
    'type' =>'',
    'description' => 'enter description',
  );
}

function chess_figure_type_form_submit(&$form, &$form_state) {
  $model_type = entity_ui_form_submit_build_entity($form, $form_state);
  $model_type->save();
  $form_state['redirect'] = 'admin/structure/chess-figure-types';
}
