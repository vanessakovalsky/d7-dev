<?php

function babyfoot_add_form($form, &$form_state, $babyfoot = NULL){
  $babyfoot = babyfoot_load($babyfoot);

  $form['title'] = array(
    '#title' => t('Babyfoot name'),
    '#type' => 'textfield',
    '#default_value' => isset($babyfoot->title) ? $babyfoot->title : '',
    '#required' => TRUE,
  );

  $form['babyfoot'] = array(
    '#type' => 'value',
    '#value' => $babyfoot,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => isset($babyfoot->bid) ? t('Update babyfoot') : t('Save babyfoot'),
    '#weight' => 50,
  );
  field_attach_form('babyfoot', $babyfoot, $form, $form_state);
  return $form;
}

function babyfoot_add_form_submit($form, &$form_state){
  $babyfoot = $form_state['values']['babyfoot'];
  if($babyfoot == NULL){
    $babyfoot = entity_get_controller('babyfoot')->create();
  }
  $babyfoot->title = $form_state['values']['title'];
  $babyfoot->type = 'babyfoot';
  $babyfoot->vid = $babyfoot->vid +1;
  field_attach_submit('babyfoot', $babyfoot, $form, $form_state);
  $babyfoot->save();
  drupal_set_message(t('The babyfoot: @title has been saved.', array('@title' => $babyfoot->title)));
  $form_state['redirect'] = 'admin/babyfoot';
}
