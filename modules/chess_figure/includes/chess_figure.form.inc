<?php
function chess_figure_type_form($form, &$form_state, $chess_type, $op = 'create'){
  if ($op == 'delete'){
    $form['submit']=array(
      '#type' => 'submit',
      '#weigth' => 50,
      '#value' => t('Delete '.$chess_type->label),
    );
    } else {

    $form['type']=array(
      '#type' => 'textfield',
      '#title' => t('Type'),
      '#size' => 60,
      '#default_value' => (isset($chess_type -> type) ? $chess_type -> type : '') ,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['label']=array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#size' => 60,
      '#default_value' => (isset($chess_type -> label) ? $chess_type -> label : ''),
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['description']=array(
      '#type' => 'textfield',
      '#title' => t('description'),
      '#size' => 60,
      '#default_value' => (isset($chess_type -> description) ? $chess_type -> description : ''),
      '#maxlength' => 1000,
    );
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save Figure type'),
      '#weight' => 40,
    );
  }
return $form;
}
function chess_figure_type_form_submit(&$form, &$form_state) {
  $model_type = entity_ui_form_submit_build_entity($form, $form_state);
  $model_type->save();
  $form_state['redirect'] = 'admin/structure/chess/figure/type';
}