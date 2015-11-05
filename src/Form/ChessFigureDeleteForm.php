<?php

namespace Drupal\chess\Form;

use Drupal\Core\Entity\ContentEntityConfirmFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

class ChessFigureDeleteForm extends ContentEntityConfirmFormBase {


  public function getQuestion() {
    return $this->t(
      'Are you sure you wont to delete entity %id of type %type?',
      array(
        '%type' => $this->entity->label(),
        '%id' => $this->entity->id()));
  }

  public function getCancelUrl() {
    return new Url('entity.content_entity_example_contact.collection');
  }

  public function getConfirmText() {
    return $this->t('Delete');
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    $entity = $this->getEntity();
    $entity->delete();

    \Drupal::logger('chess')->notise('@type: delete %title',
      array(
        '@type' => $this->entity->bundle(),
        '%title' => $this->entity->label(),
      ));
    $form_state->setRedirect('entity.chess_chess_figure.collection');

  }
}
