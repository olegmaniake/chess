<?php

namespace Drupal\chess\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

class ChessFigureSettingsForm extends FormBase {

  public function getFormId() {
    return 'chess_settings';
  }


  public function buildForm(array $form, FormStateInterface $form_state) {
    $form['chess_setings']['#markup'] = 'Setings form for Chess.';
    return $form;
  }


  public function submitForm(array &$form, FormStateInterface $form_state) {
    // TODO: Implement submitForm() method.
  }
}
